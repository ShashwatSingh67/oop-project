/********************************************************************************
** Form generated from reading UI file 'usertrades.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERTRADES_H
#define UI_USERTRADES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_usertrades
{
public:
    QGridLayout *gridLayout;
    QPushButton *Home_Button;
    QTableWidget *tableWidget_User_Data;

    void setupUi(QDialog *usertrades)
    {
        if (usertrades->objectName().isEmpty())
            usertrades->setObjectName("usertrades");
        usertrades->resize(1280, 720);
        gridLayout = new QGridLayout(usertrades);
        gridLayout->setObjectName("gridLayout");
        Home_Button = new QPushButton(usertrades);
        Home_Button->setObjectName("Home_Button");
        Home_Button->setMinimumSize(QSize(0, 31));

        gridLayout->addWidget(Home_Button, 0, 0, 1, 1);

        tableWidget_User_Data = new QTableWidget(usertrades);
        if (tableWidget_User_Data->columnCount() < 7)
            tableWidget_User_Data->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_User_Data->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_User_Data->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_User_Data->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_User_Data->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_User_Data->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_User_Data->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_User_Data->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget_User_Data->setObjectName("tableWidget_User_Data");
        tableWidget_User_Data->setMinimumSize(QSize(256, 192));
        tableWidget_User_Data->setMaximumSize(QSize(1920, 1080));
        tableWidget_User_Data->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget_User_Data->verticalHeader()->setVisible(true);
        tableWidget_User_Data->verticalHeader()->setCascadingSectionResizes(false);

        gridLayout->addWidget(tableWidget_User_Data, 1, 0, 1, 1);


        retranslateUi(usertrades);

        QMetaObject::connectSlotsByName(usertrades);
    } // setupUi

    void retranslateUi(QDialog *usertrades)
    {
        usertrades->setWindowTitle(QCoreApplication::translate("usertrades", "Dialog", nullptr));
        Home_Button->setText(QCoreApplication::translate("usertrades", "Home", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_User_Data->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("usertrades", "Bot ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_User_Data->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("usertrades", "Strategy Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_User_Data->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("usertrades", "Variance Enabled", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_User_Data->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("usertrades", "Profit/Loss", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_User_Data->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("usertrades", "Buy Order", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_User_Data->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("usertrades", "Sell Order", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_User_Data->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("usertrades", "Trade Volume", nullptr));
    } // retranslateUi

};

namespace Ui {
    class usertrades: public Ui_usertrades {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERTRADES_H
