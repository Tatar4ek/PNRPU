/********************************************************************************
** Form generated from reading UI file 'newedge.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWEDGE_H
#define UI_NEWEDGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_newedge
{
public:
    QPushButton *NewEdgeButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *newedge)
    {
        if (newedge->objectName().isEmpty())
            newedge->setObjectName(QString::fromUtf8("newedge"));
        newedge->resize(456, 237);
        newedge->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        NewEdgeButton = new QPushButton(newedge);
        NewEdgeButton->setObjectName(QString::fromUtf8("NewEdgeButton"));
        NewEdgeButton->setGeometry(QRect(140, 170, 181, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        NewEdgeButton->setFont(font);
        label = new QLabel(newedge);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Black"));
        font1.setPointSize(12);
        label->setFont(font1);
        label_2 = new QLabel(newedge);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 20, 61, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(newedge);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 20, 121, 31));
        label_3->setFont(font1);

        retranslateUi(newedge);

        QMetaObject::connectSlotsByName(newedge);
    } // setupUi

    void retranslateUi(QDialog *newedge)
    {
        newedge->setWindowTitle(QApplication::translate("newedge", "Dialog", nullptr));
        NewEdgeButton->setText(QApplication::translate("newedge", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\320\261\321\200\320\276", nullptr));
        label->setText(QApplication::translate("newedge", "\320\236\321\202\320\272\321\203\320\264\320\260", nullptr));
        label_2->setText(QApplication::translate("newedge", "\320\232\321\203\320\264\320\260", nullptr));
        label_3->setText(QApplication::translate("newedge", "\320\222\320\265\321\201 \320\240\320\265\320\261\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newedge: public Ui_newedge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWEDGE_H
