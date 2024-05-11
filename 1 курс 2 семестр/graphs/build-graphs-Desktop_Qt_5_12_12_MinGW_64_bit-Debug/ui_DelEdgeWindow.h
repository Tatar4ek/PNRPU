/********************************************************************************
** Form generated from reading UI file 'DelEdgeWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELEDGEWINDOW_H
#define UI_DELEDGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DelEdgeWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *FromLine;
    QPushButton *DelEdgeBtn;
    QLabel *label_3;
    QLineEdit *ToLine;

    void setupUi(QDialog *DelEdgeWindow)
    {
        if (DelEdgeWindow->objectName().isEmpty())
            DelEdgeWindow->setObjectName(QString::fromUtf8("DelEdgeWindow"));
        DelEdgeWindow->resize(351, 300);
        label = new QLabel(DelEdgeWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 201, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(DelEdgeWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 161, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        label_2->setFont(font1);
        FromLine = new QLineEdit(DelEdgeWindow);
        FromLine->setObjectName(QString::fromUtf8("FromLine"));
        FromLine->setGeometry(QRect(10, 140, 161, 41));
        DelEdgeBtn = new QPushButton(DelEdgeWindow);
        DelEdgeBtn->setObjectName(QString::fromUtf8("DelEdgeBtn"));
        DelEdgeBtn->setGeometry(QRect(100, 194, 161, 71));
        QFont font2;
        font2.setPointSize(12);
        DelEdgeBtn->setFont(font2);
        label_3 = new QLabel(DelEdgeWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 70, 161, 71));
        label_3->setFont(font1);
        ToLine = new QLineEdit(DelEdgeWindow);
        ToLine->setObjectName(QString::fromUtf8("ToLine"));
        ToLine->setGeometry(QRect(180, 140, 161, 41));

        retranslateUi(DelEdgeWindow);

        QMetaObject::connectSlotsByName(DelEdgeWindow);
    } // setupUi

    void retranslateUi(QDialog *DelEdgeWindow)
    {
        DelEdgeWindow->setWindowTitle(QApplication::translate("DelEdgeWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("DelEdgeWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\320\265\320\261\321\200\320\276", nullptr));
        label_2->setText(QApplication::translate("DelEdgeWindow", "\320\235\320\276\320\274\320\265\321\200 \320\262\320\265\321\200\321\210\320\270\320\275\321\213:", nullptr));
        DelEdgeBtn->setText(QApplication::translate("DelEdgeWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("DelEdgeWindow", "\320\235\320\276\320\274\320\265\321\200 \320\262\320\265\321\200\321\210\320\270\320\275\321\213:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DelEdgeWindow: public Ui_DelEdgeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELEDGEWINDOW_H
