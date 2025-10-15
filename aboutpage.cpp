#include "homewindow.h"
#include "mainwindow.h"
#include "botsoverview.h"
#include "usertrades.h"
#include "aboutpage.h"
#include "ui_aboutpage.h"

aboutpage::aboutpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::aboutpage)
{
    ui->setupUi(this);
}

aboutpage::~aboutpage()
{
    delete ui;
}

void aboutpage::on_Home_Button_clicked()
{
    homewindow *homeWin = new homewindow();
    homeWin->show();
    this->hide(); // or this->close()
}

