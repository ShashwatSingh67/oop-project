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

