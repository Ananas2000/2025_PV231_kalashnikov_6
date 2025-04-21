#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), watcher(new QFileSystemWatcher(this)) {
    ui->setupUi(this);
    connect(watcher, &QFileSystemWatcher::directoryChanged, this, &MainWindow::directoryChanged);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_selectDirectory_clicked() {
    QString dir = QFileDialog::getExistingDirectory(this, "Выберите директорию");
    if (!dir.isEmpty()) {
        currentDir = dir;
        ui->logArea->append("Выбрана директория: " + dir);
        updateFileList();
    }
}

void MainWindow::on_startMonitoring_clicked() {
    if (!currentDir.isEmpty()) {
        watcher->addPath(currentDir);
        for (const QString &file : currentFiles) {
            watcher->addPath(currentDir + "/" + file);
        }
        ui->logArea->append("Мониторинг запущен");
    }
}

void MainWindow::on_stopMonitoring_clicked() {
    watcher->removePaths(watcher->directories());
    watcher->removePaths(watcher->files());
    ui->logArea->append("Мониторинг остановлен");
}

void MainWindow::on_clearLog_clicked() {
    ui->logArea->clear();
}

void MainWindow::directoryChanged(const QString &path) {
    Q_UNUSED(path);
    QList<QString> oldFiles = currentFiles;
    updateFileList();
    detectRenamedFiles(oldFiles, currentFiles);

    // Обновляем отслеживаемые файлы
    watcher->addPath(currentDir);
    for (const QString &file : currentFiles) {
        watcher->addPath(currentDir + "/" + file);
    }
}

void MainWindow::detectRenamedFiles(const QList<QString>& oldFiles, const QList<QString>& newFiles) {
    QList<QString> added = QSet<QString>(newFiles.begin(), newFiles.end())
    .subtract(QSet<QString>(oldFiles.begin(), oldFiles.end()))
        .values();

    QList<QString> removed = QSet<QString>(oldFiles.begin(), oldFiles.end())
                                 .subtract(QSet<QString>(newFiles.begin(), newFiles.end()))
                                 .values();

    // Определяем переименования (1:1)
    if (added.size() == 1 && removed.size() == 1) {
        logEvent(QString("Файл переименован: '%1' -> '%2'")
                     .arg(removed.first())
                     .arg(added.first()));
        return;
    }

    // Логируем оставшиеся изменения
    for (const QString &file : removed) {
        logEvent("Удален файл: " + file);
    }
    for (const QString &file : added) {
        logEvent("Добавлен файл: " + file);
    }
}

void MainWindow::updateFileList() {
    currentFiles = QDir(currentDir).entryList(QDir::Files);
}

void MainWindow::logEvent(const QString &message) {
    QString timestamp = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");
    QString logMessage = "[" + timestamp + "] " + message;
    ui->logArea->append(logMessage);
    logToFile(logMessage);
}

void MainWindow::logToFile(const QString &message) {
    QFile file("log.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << message << "\n";
        file.close();
    }
}
