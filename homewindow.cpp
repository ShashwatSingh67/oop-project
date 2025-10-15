#include "homewindow.h"
#include "mainwindow.h"
#include "botsoverview.h"
#include "usertrades.h"
#include "aboutpage.h"
#include "ui_homewindow.h"

#include <QMessageBox>
#include <QPixmap>


homewindow::homewindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::homewindow)
{
    ui->setupUi(this);
    QPixmap pix("Screenshot 2025-10-15 232950.png");
    ui->label->setPixmap(pix);

}

homewindow::~homewindow()
{
    delete ui;
}

void homewindow::on_MarketData_Button_clicked()
{
    // Create an instance of MainWindow
    MainWindow *mainWin = new MainWindow();

    // Show it
    mainWin->show();

    // Optionally, hide or close the current home window
    this->hide(); // hides the homewindow
    // or this->close(); // closes it completely
}


void homewindow::on_BotsOverview_Button_clicked()
{
    botsoverview *botsOver = new botsoverview();
    botsOver->show();
    this->hide(); // or this->close()
}


void homewindow::on_UserTrades_Button_clicked()
{
    usertrades *userTrad = new usertrades();
    userTrad->show();
    this->hide(); // or this->close()
}


void homewindow::on_About_Button_clicked()
{
    aboutpage *aboutPg = new aboutpage();
    aboutPg->show();
    this->hide(); // or this->close()
}

