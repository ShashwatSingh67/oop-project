#include "stockgraph.h"
#include "ui_stockgraph.h"
#include "homewindow.h"
#include "mainwindow.h"
#include "botsoverview.h"
#include "usertrades.h"
#include "aboutpage.h"
#include "ui_mainwindow.h"

stockgraph::stockgraph(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stockgraph)
{
    ui->setupUi(this);

    // 1️⃣ Create the data series
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

    // 2️⃣ Create the chart
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0, 12);
    chart->axes(Qt::Horizontal).first()->setRange(0, 12);

    // 3️⃣ Create a chart view to display it
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);

    // 4️⃣ Put it inside your QWidget named "widgetGraph"
    QVBoxLayout *layout = new QVBoxLayout(ui->widgetGraph);
    layout->setContentsMargins(0, 0, 0, 0);  // remove padding
    layout->addWidget(chartview);

    // Optional: force layout update
    ui->widgetGraph->setLayout(layout);
}

stockgraph::~stockgraph()
{
    delete ui;
}

void stockgraph::on_backButton_clicked()
{
        // Create an instance of MainWindow
        MainWindow *mainWin = new MainWindow();

        // Show it
        mainWin->show();

        // Optionally, hide or close the current home window
        this->hide(); // hides the homewindow
        // or this->close(); // closes it completely
}

