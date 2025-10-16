#include "stockgraph.h"
#include "ui_stockgraph.h"

stockgraph::stockgraph(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stockgraph)
{
    ui->setupUi(this);
}

stockgraph::~stockgraph()
{
    delete ui;
}
