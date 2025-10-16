#include "homewindow.h"
#include "mainwindow.h"
#include "botsoverview.h"
#include "usertrades.h"
#include "aboutpage.h"
#include "ui_botsoverview.h"

botsoverview::botsoverview(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::botsoverview)
{
    ui->setupUi(this);

    ui->tableWidget_Bot_Data->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

    ui->tableWidget_Bot_Data->setRowCount(50);
    for (int i = 0; i < 50; i++){
        ui->tableWidget_Bot_Data->setItem(i,0,new QTableWidgetItem(QString("100")));
        ui->tableWidget_Bot_Data->setItem(i,1,new QTableWidgetItem(QString("Mean Reversion")));
        ui->tableWidget_Bot_Data->setItem(i,2,new QTableWidgetItem(QString("Yes")));
        ui->tableWidget_Bot_Data->setItem(i,3,new QTableWidgetItem(QString("200")));
        ui->tableWidget_Bot_Data->setItem(i,4,new QTableWidgetItem(QString("???")));
        ui->tableWidget_Bot_Data->setItem(i,5,new QTableWidgetItem(QString("?")));
        ui->tableWidget_Bot_Data->setItem(i,6,new QTableWidgetItem(QString("??")));
    }

    ui->tableWidget_Bot_Data->setVisible(true);
}

botsoverview::~botsoverview()
{
    delete ui;
}

void botsoverview::on_Home_Button_clicked()
{
    homewindow *homeWin = new homewindow();
    homeWin->show();
    this->hide(); // or this->close()
}

