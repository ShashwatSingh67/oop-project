#ifndef USERTRADES_H
#define USERTRADES_H

#include <QDialog>

namespace Ui {
class usertrades;
}

class usertrades : public QDialog
{
    Q_OBJECT

public:
    explicit usertrades(QWidget *parent = nullptr);
    ~usertrades();

private slots:
    void on_Home_Button_clicked();

private:
    Ui::usertrades *ui;
};

#endif // USERTRADES_H
