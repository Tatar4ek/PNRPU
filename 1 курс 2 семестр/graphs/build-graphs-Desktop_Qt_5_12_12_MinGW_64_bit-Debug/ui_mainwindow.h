/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *PrintGraph;
    QPushButton *NodeBtn;
    QPushButton *EdgeBtn;
    QPushButton *DelEdgeBtn;
    QPushButton *DelNodeBtn;
    QPushButton *TspBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PrintGraph = new QGraphicsView(centralwidget);
        PrintGraph->setObjectName(QString::fromUtf8("PrintGraph"));
        PrintGraph->setGeometry(QRect(30, 10, 701, 381));
        NodeBtn = new QPushButton(centralwidget);
        NodeBtn->setObjectName(QString::fromUtf8("NodeBtn"));
        NodeBtn->setGeometry(QRect(50, 430, 80, 25));
        EdgeBtn = new QPushButton(centralwidget);
        EdgeBtn->setObjectName(QString::fromUtf8("EdgeBtn"));
        EdgeBtn->setGeometry(QRect(150, 430, 80, 25));
        DelEdgeBtn = new QPushButton(centralwidget);
        DelEdgeBtn->setObjectName(QString::fromUtf8("DelEdgeBtn"));
        DelEdgeBtn->setGeometry(QRect(270, 430, 80, 25));
        DelNodeBtn = new QPushButton(centralwidget);
        DelNodeBtn->setObjectName(QString::fromUtf8("DelNodeBtn"));
        DelNodeBtn->setGeometry(QRect(400, 440, 80, 25));
        TspBtn = new QPushButton(centralwidget);
        TspBtn->setObjectName(QString::fromUtf8("TspBtn"));
        TspBtn->setGeometry(QRect(60, 490, 80, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        NodeBtn->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        EdgeBtn->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        DelEdgeBtn->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        DelNodeBtn->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        TspBtn->setText(QApplication::translate("MainWindow", "TSP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
