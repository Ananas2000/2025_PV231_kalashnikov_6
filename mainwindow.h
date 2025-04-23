#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemWatcher>
#include <QList>
#include "SmartPoint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_selectDirectory_clicked();
    void on_startMonitoring_clicked();
    void on_stopMonitoring_clicked();
    void on_ClearLog_clicked();
    void directoryChanged(const QString &path);

private:
    Ui::MainWindow *ui;
    SmartPointer<QFileSystemWatcher> watcher;
    QString currentDir;
    QList<QString> currentFiles;
    QMap<QString, QDateTime> fileTimestamps;

    void updateFileList();
    void logEvent(const QString &message);
    void logToFile(const QString &message);
    void detectRenamedFiles(const QList<QString>& oldFiles, const QList<QString>& newFiles);
};

#endif // MAINWINDOW_H
