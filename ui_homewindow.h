/********************************************************************************
** Form generated from reading UI file 'homewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_homewindow
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QPushButton *MarketData_Button;
    QPushButton *Home_Button;
    QPushButton *UserTrades_Button;
    QPushButton *BotsOverview_Button;
    QPushButton *About_Button;
    QLabel *label;

    void setupUi(QDialog *homewindow)
    {
        if (homewindow->objectName().isEmpty())
            homewindow->setObjectName("homewindow");
        homewindow->resize(1280, 720);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        homewindow->setPalette(palette);
        QFont font;
        font.setKerning(true);
        homewindow->setFont(font);
        gridLayout = new QGridLayout(homewindow);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(homewindow);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        MarketData_Button = new QPushButton(frame);
        MarketData_Button->setObjectName("MarketData_Button");
        MarketData_Button->setGeometry(QRect(260, 10, 251, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        MarketData_Button->setPalette(palette1);
        QFont font1;
        font1.setPointSize(12);
        font1.setKerning(true);
        MarketData_Button->setFont(font1);
        Home_Button = new QPushButton(frame);
        Home_Button->setObjectName("Home_Button");
        Home_Button->setGeometry(QRect(10, 10, 251, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        Home_Button->setPalette(palette2);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setKerning(true);
        Home_Button->setFont(font2);
        UserTrades_Button = new QPushButton(frame);
        UserTrades_Button->setObjectName("UserTrades_Button");
        UserTrades_Button->setGeometry(QRect(510, 10, 251, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette3.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette3.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette3.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        UserTrades_Button->setPalette(palette3);
        UserTrades_Button->setFont(font1);
        BotsOverview_Button = new QPushButton(frame);
        BotsOverview_Button->setObjectName("BotsOverview_Button");
        BotsOverview_Button->setGeometry(QRect(760, 10, 251, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette4.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette4.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette4.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        BotsOverview_Button->setPalette(palette4);
        BotsOverview_Button->setFont(font1);
        About_Button = new QPushButton(frame);
        About_Button->setObjectName("About_Button");
        About_Button->setGeometry(QRect(1010, 10, 241, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette5.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette5.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette5.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        About_Button->setPalette(palette5);
        About_Button->setFont(font1);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setGeometry(QRect(0, 10, 1274, 720));
        label->setMinimumSize(QSize(1, 1));
        QPalette palette6;
        palette6.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette6.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        label->setPalette(palette6);
        label->setPixmap(QPixmap(QString::fromUtf8("build/Screenshot 2025-10-15 232950.png")));
        label->raise();
        MarketData_Button->raise();
        Home_Button->raise();
        UserTrades_Button->raise();
        BotsOverview_Button->raise();
        About_Button->raise();

        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(homewindow);

        QMetaObject::connectSlotsByName(homewindow);
    } // setupUi

    void retranslateUi(QDialog *homewindow)
    {
        homewindow->setWindowTitle(QCoreApplication::translate("homewindow", "Dialog", nullptr));
        MarketData_Button->setText(QCoreApplication::translate("homewindow", "Market Data", nullptr));
        Home_Button->setText(QCoreApplication::translate("homewindow", "Home", nullptr));
        UserTrades_Button->setText(QCoreApplication::translate("homewindow", "User Trades", nullptr));
        BotsOverview_Button->setText(QCoreApplication::translate("homewindow", "Bots Overview", nullptr));
        About_Button->setText(QCoreApplication::translate("homewindow", "About", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class homewindow: public Ui_homewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
