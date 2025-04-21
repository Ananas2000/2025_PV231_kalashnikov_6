/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *selectDirectory;
    QPushButton *startMonitoring;
    QPushButton *stopMonitoring;
    QPushButton *clearLog;
    QSpacerItem *verticalSpacer;
    QTextEdit *logArea;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        selectDirectory = new QPushButton(centralwidget);
        selectDirectory->setObjectName("selectDirectory");

        verticalLayout->addWidget(selectDirectory);

        startMonitoring = new QPushButton(centralwidget);
        startMonitoring->setObjectName("startMonitoring");

        verticalLayout->addWidget(startMonitoring);

        stopMonitoring = new QPushButton(centralwidget);
        stopMonitoring->setObjectName("stopMonitoring");

        verticalLayout->addWidget(stopMonitoring);

        clearLog = new QPushButton(centralwidget);
        clearLog->setObjectName("clearLog");

        verticalLayout->addWidget(clearLog);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        logArea = new QTextEdit(centralwidget);
        logArea->setObjectName("logArea");
        logArea->setReadOnly(true);

        horizontalLayout->addWidget(logArea);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "File Monitor", nullptr));
        selectDirectory->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\216", nullptr));
        startMonitoring->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\274\320\276\320\275\320\270\321\202\320\276\321\200\320\270\320\275\320\263", nullptr));
        stopMonitoring->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\274\320\276\320\275\320\270\321\202\320\276\321\200\320\270\320\275\320\263", nullptr));
        clearLog->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\273\320\276\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
