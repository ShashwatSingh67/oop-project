#ifndef BOTSOVERVIEW_H
#define BOTSOVERVIEW_H

#include <QDialog>

namespace Ui {
class botsoverview;
}

class botsoverview : public QDialog
{
    Q_OBJECT

public:
    explicit botsoverview(QWidget *parent = nullptr);
    ~botsoverview();

private slots:
    void on_Home_Button_clicked();

private:
    Ui::botsoverview *ui;
};

#endif // BOTSOVERVIEW_H
