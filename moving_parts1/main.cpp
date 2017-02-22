#include "mainwindow.h"
#include <QApplication>

#define DASH_WIDTH 1280
#define DASH_HEIGHT 720

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(DASH_WIDTH, DASH_HEIGHT);
    w.show();

    return a.exec();
}
