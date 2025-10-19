/********************************************************************************
** Form generated from reading UI file 'aboutpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTPAGE_H
#define UI_ABOUTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_aboutpage
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *Home_Button;
    QFrame *frame;
    QLabel *label;

    void setupUi(QDialog *aboutpage)
    {
        if (aboutpage->objectName().isEmpty())
            aboutpage->setObjectName("aboutpage");
        aboutpage->resize(1280, 720);
        gridLayout_2 = new QGridLayout(aboutpage);
        gridLayout_2->setObjectName("gridLayout_2");
        Home_Button = new QPushButton(aboutpage);
        Home_Button->setObjectName("Home_Button");
        Home_Button->setMinimumSize(QSize(0, 31));

        gridLayout_2->addWidget(Home_Button, 0, 0, 1, 1);

        frame = new QFrame(aboutpage);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 90, 1081, 401));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        gridLayout_2->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(aboutpage);

        QMetaObject::connectSlotsByName(aboutpage);
    } // setupUi

    void retranslateUi(QDialog *aboutpage)
    {
        aboutpage->setWindowTitle(QCoreApplication::translate("aboutpage", "Dialog", nullptr));
        Home_Button->setText(QCoreApplication::translate("aboutpage", "Home", nullptr));
        label->setText(QCoreApplication::translate("aboutpage", "Project Description:\n"
"\n"
"This project will function as a paper stock exchange, with the option to customize past data for stocks and\n"
"commodities that can be loaded in. This data will be used to train a variety of trading bots that each use different\n"
"strategies, which then compete in an open order book format to see which makes the most profit over the\n"
"greatest amount of time.\n"
"\n"
"\n"
"Aim of the project:\n"
"\n"
"Compare the results of different algorithmic trading bots on a custom backtester in order to improve and gain\n"
"insight on trading strategies.\n"
"\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aboutpage: public Ui_aboutpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTPAGE_H
