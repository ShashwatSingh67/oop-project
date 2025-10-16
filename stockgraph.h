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

private:
    Ui::stockgraph *ui;
};

#endif // STOCKGRAPH_H
