#include "homewindow.h"
#include "mainwindow.h"
#include "botsoverview.h"
#include "usertrades.h"
#include "aboutpage.h"
#include "ui_usertrades.h"

usertrades::usertrades(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::usertrades)
{
    ui->setupUi(this);

    ui->tableWidget_User_Data->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
}

usertrades::~usertrades()
{
    delete ui;
}

void usertrades::on_Home_Button_clicked()
{
    homewindow *homeWin = new homewindow();
    homeWin->show();
    this->hide(); // or this->close()
}

