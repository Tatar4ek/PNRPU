/********************************************************************************
** Form generated from reading UI file 'NewEdgeWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWEDGEWINDOW_H
#define UI_NEWEDGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NewEdgeWindow
{
public:
    QPushButton *NewEdgeButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *FromLine;
    QLineEdit *ToLine;
    QLineEdit *WeightLine;

    void setupUi(QDialog *NewEdgeWindow)
    {
        if (NewEdgeWindow->objectName().isEmpty())
            NewEdgeWindow->setObjectName(QString::fromUtf8("NewEdgeWindow"));
        NewEdgeWindow->setWindowModality(Qt::NonModal);
        NewEdgeWindow->setEnabled(true);
        NewEdgeWindow->resize(454, 212);
        NewEdgeWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(235, 255, 206);\n"
"\n"
""));
        NewEdgeButton = new QPushButton(NewEdgeWindow);
        NewEdgeButton->setObjectName(QString::fromUtf8("NewEdgeButton"));
        NewEdgeButton->setGeometry(QRect(130, 130, 181, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        NewEdgeButton->setFont(font);
        NewEdgeButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label = new QLabel(NewEdgeWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Black"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        font1.setKerning(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(NewEdgeWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 20, 61, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Black"));
        font2.setPointSize(12);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_3 = new QLabel(NewEdgeWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 20, 121, 31));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        FromLine = new QLineEdit(NewEdgeWindow);
        FromLine->setObjectName(QString::fromUtf8("FromLine"));
        FromLine->setGeometry(QRect(20, 70, 113, 24));
        ToLine = new QLineEdit(NewEdgeWindow);
        ToLine->setObjectName(QString::fromUtf8("ToLine"));
        ToLine->setGeometry(QRect(160, 70, 113, 24));
        WeightLine = new QLineEdit(NewEdgeWindow);
        WeightLine->setObjectName(QString::fromUtf8("WeightLine"));
        WeightLine->setGeometry(QRect(310, 70, 113, 24));

        retranslateUi(NewEdgeWindow);

        QMetaObject::connectSlotsByName(NewEdgeWindow);
    } // setupUi

    void retranslateUi(QDialog *NewEdgeWindow)
    {
        NewEdgeWindow->setWindowTitle(QApplication::translate("NewEdgeWindow", "Dialog", nullptr));
        NewEdgeButton->setText(QApplication::translate("NewEdgeWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\320\261\321\200\320\276", nullptr));
        label->setText(QApplication::translate("NewEdgeWindow", "\320\236\321\202\320\272\321\203\320\264\320\260", nullptr));
        label_2->setText(QApplication::translate("NewEdgeWindow", "\320\232\321\203\320\264\320\260", nullptr));
        label_3->setText(QApplication::translate("NewEdgeWindow", "\320\222\320\265\321\201 \320\240\320\265\320\261\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewEdgeWindow: public Ui_NewEdgeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWEDGEWINDOW_H
