#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QDialog>

namespace Ui {
class homewindow;
}

class homewindow : public QDialog
{
    Q_OBJECT

public:
    explicit homewindow(QWidget *parent = nullptr);
    ~homewindow();

private slots:
    void on_MarketData_Button_clicked();

    void on_BotsOverview_Button_clicked();

    void on_UserTrades_Button_clicked();

    void on_About_Button_clicked();

private:
    Ui::homewindow *ui;
};

#endif // HOMEWINDOW_H
