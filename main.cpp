#include "mainwindow.h"
#include "homewindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // Setting app style
    QFile styleSheetFile("./Incrypt.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);


    homewindow w;
    w.show();
    return a.exec();
}
