/********************************************************************************
** Form generated from reading UI file 'botsoverview.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOTSOVERVIEW_H
#define UI_BOTSOVERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_botsoverview
{
public:
    QGridLayout *gridLayout;
    QPushButton *Home_Button;
    QTableWidget *tableWidget_Bot_Data;

    void setupUi(QDialog *botsoverview)
    {
        if (botsoverview->objectName().isEmpty())
            botsoverview->setObjectName("botsoverview");
        botsoverview->resize(1280, 720);
        gridLayout = new QGridLayout(botsoverview);
        gridLayout->setObjectName("gridLayout");
        Home_Button = new QPushButton(botsoverview);
        Home_Button->setObjectName("Home_Button");
        Home_Button->setMinimumSize(QSize(0, 31));

        gridLayout->addWidget(Home_Button, 1, 0, 1, 1);

        tableWidget_Bot_Data = new QTableWidget(botsoverview);
        if (tableWidget_Bot_Data->columnCount() < 7)
            tableWidget_Bot_Data->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Bot_Data->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Bot_Data->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Bot_Data->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Bot_Data->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Bot_Data->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Bot_Data->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Bot_Data->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget_Bot_Data->setObjectName("tableWidget_Bot_Data");
        tableWidget_Bot_Data->setMinimumSize(QSize(256, 192));
        tableWidget_Bot_Data->setMaximumSize(QSize(1920, 1080));
        tableWidget_Bot_Data->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget_Bot_Data->verticalHeader()->setVisible(true);
        tableWidget_Bot_Data->verticalHeader()->setCascadingSectionResizes(false);

        gridLayout->addWidget(tableWidget_Bot_Data, 2, 0, 1, 1);


        retranslateUi(botsoverview);

        QMetaObject::connectSlotsByName(botsoverview);
    } // setupUi

    void retranslateUi(QDialog *botsoverview)
    {
        botsoverview->setWindowTitle(QCoreApplication::translate("botsoverview", "Dialog", nullptr));
        Home_Button->setText(QCoreApplication::translate("botsoverview", "Home", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Bot_Data->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("botsoverview", "Bot ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Bot_Data->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("botsoverview", "Strategy Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Bot_Data->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("botsoverview", "Variance Enabled", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Bot_Data->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("botsoverview", "Profit/Loss", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Bot_Data->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("botsoverview", "Buy Order", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Bot_Data->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("botsoverview", "Sell Order", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Bot_Data->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("botsoverview", "Trade Volume", nullptr));
    } // retranslateUi

};

namespace Ui {
    class botsoverview: public Ui_botsoverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTSOVERVIEW_H
