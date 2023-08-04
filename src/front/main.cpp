#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // Need for double number dot instead of comma
//      setlocale(LC_NUMERIC, "C");
    return a.exec();
}
