#include "mainwindow.h"
#include "speedreadwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow startingWindow;
    startingWindow.show();

    return a.exec();
}
