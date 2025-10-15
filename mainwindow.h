#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtCore>
#include <QtGui>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_tableWidget_Item_Data_cellClicked(int row, int column);

    void on_tableWidget_Item_Data_cellDoubleClicked(int row, int column);

    void on_MarketData_Button_clicked();

    void on_Home_Button_clicked();

    void on_BotsOverview_Button_clicked();

    void on_UserTrades_Button_clicked();

    void on_About_Button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
