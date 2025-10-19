/********************************************************************************
** Form generated from reading UI file 'stockgraph.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKGRAPH_H
#define UI_STOCKGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stockgraph
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QLineEdit *lineEdit;
    QWidget *widgetGraph;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QFrame *frame_2;
    QPushButton *backButton;

    void setupUi(QDialog *stockgraph)
    {
        if (stockgraph->objectName().isEmpty())
            stockgraph->setObjectName("stockgraph");
        stockgraph->resize(1280, 720);
        gridLayout = new QGridLayout(stockgraph);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(stockgraph);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(980, 360, 151, 24));
        widgetGraph = new QWidget(frame);
        widgetGraph->setObjectName("widgetGraph");
        widgetGraph->setGeometry(QRect(30, 120, 821, 561));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1010, 290, 101, 41));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(1000, 470, 101, 41));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(980, 540, 151, 24));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(30, 20, 1201, 61));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        backButton = new QPushButton(frame_2);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 10, 121, 41));

        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(stockgraph);

        QMetaObject::connectSlotsByName(stockgraph);
    } // setupUi

    void retranslateUi(QDialog *stockgraph)
    {
        stockgraph->setWindowTitle(QCoreApplication::translate("stockgraph", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("stockgraph", "Buy Amount", nullptr));
        pushButton_2->setText(QCoreApplication::translate("stockgraph", "Sell Amount", nullptr));
        backButton->setText(QCoreApplication::translate("stockgraph", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stockgraph: public Ui_stockgraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKGRAPH_H
