#ifndef STOCKGRAPH_H
#define STOCKGRAPH_H

#include <QDialog>

namespace Ui {
class stockgraph;
}

class stockgraph : public QDialog
{
    Q_OBJECT

public:
    explicit stockgraph(QWidget *parent = nullptr);
    ~stockgraph();

private slots:
    void on_pushButton_3_clicked();

    void on_backButton_clicked();

private:
    Ui::stockgraph *ui;
};

#endif // STOCKGRAPH_H
