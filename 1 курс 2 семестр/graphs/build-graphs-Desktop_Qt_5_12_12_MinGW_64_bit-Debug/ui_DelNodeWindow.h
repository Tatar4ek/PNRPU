/********************************************************************************
** Form generated from reading UI file 'DelNodeWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELNODEWINDOW_H
#define UI_DELNODEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DelNodeWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *NumberLine;
    QPushButton *DelNodeBtn;

    void setupUi(QDialog *DelNodeWindow)
    {
        if (DelNodeWindow->objectName().isEmpty())
            DelNodeWindow->setObjectName(QString::fromUtf8("DelNodeWindow"));
        DelNodeWindow->resize(400, 300);
        label = new QLabel(DelNodeWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 10, 201, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(DelNodeWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 60, 151, 41));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        NumberLine = new QLineEdit(DelNodeWindow);
        NumberLine->setObjectName(QString::fromUtf8("NumberLine"));
        NumberLine->setGeometry(QRect(112, 103, 151, 51));
        DelNodeBtn = new QPushButton(DelNodeWindow);
        DelNodeBtn->setObjectName(QString::fromUtf8("DelNodeBtn"));
        DelNodeBtn->setGeometry(QRect(120, 190, 131, 61));
        DelNodeBtn->setFont(font1);

        retranslateUi(DelNodeWindow);

        QMetaObject::connectSlotsByName(DelNodeWindow);
    } // setupUi

    void retranslateUi(QDialog *DelNodeWindow)
    {
        DelNodeWindow->setWindowTitle(QApplication::translate("DelNodeWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("DelNodeWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\320\265\321\200\321\210\320\270\320\275\321\203", nullptr));
        label_2->setText(QApplication::translate("DelNodeWindow", "\320\235\320\276\320\274\320\265\321\200 \320\262\320\265\321\200\321\210\320\270\320\275\321\213:", nullptr));
        DelNodeBtn->setText(QApplication::translate("DelNodeWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DelNodeWindow: public Ui_DelNodeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELNODEWINDOW_H
