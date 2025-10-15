#include "homewindow.h"
#include "mainwindow.h"
#include "botsoverview.h"
#include "usertrades.h"
#include "aboutpage.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

connect(ui->tableWidget_Item_Data, &QTableWidget::cellDoubleClicked,
    this, &MainWindow::on_tableWidget_Item_Data_cellDoubleClicked);

    ui->tableWidget_Item_Data->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

    ui->tableWidget_Item_Data->setRowCount(50);
    for (int i = 0; i < 50; i++){
        ui->tableWidget_Item_Data->setItem(i,0,new QTableWidgetItem(QString("00000")));
        ui->tableWidget_Item_Data->setItem(i,1,new QTableWidgetItem(QString("stockname")));
        ui->tableWidget_Item_Data->setItem(i,2,new QTableWidgetItem(QString("$100")));
        ui->tableWidget_Item_Data->setItem(i,3,new QTableWidgetItem(QString("$68")));
    }

    ui->tableWidget_Item_Data->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QLineSeries *series = new QLineSeries();

    series->append(0, 3);
    series->append(1, 2);
    series->append(2, 8);
    series->append(3, 6);
    series->append(4, 4);
    series->append(5, 9);
    series->append(6, 2);
    series->append(7, 1);
    series->append(8, 6);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0,12);
    chart->axes(Qt::Horizontal).first()->setRange(0,12);
    chart->setVisible(true);

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setVisible(true);

    setCentralWidget(chartview);
}

/*
void MainWindow::on_tableWidget_Item_Data_cellDoubleClicked(int row, int column)
{
    qDebug() << ui->tableWidget_Item_Data->itemAt(row,column)->on_pushButton_clicked();
}
*/

void MainWindow::on_tableWidget_Item_Data_cellDoubleClicked(int row, int column)
{
    Q_UNUSED(row);
    Q_UNUSED(column);

    // Simply call your existing function
    on_pushButton_clicked();
}

void MainWindow::on_MarketData_Button_clicked()
{
    // Toggle visibility
    //bool isVisible = ui->tableWidget_Item_Data->isVisible();
    //ui->tableWidget_Item_Data->setVisible(!isVisible);
}

void MainWindow::on_Home_Button_clicked()
{
    homewindow *homeWin = new homewindow();
    homeWin->show();
    this->hide(); // or this->close()
}

