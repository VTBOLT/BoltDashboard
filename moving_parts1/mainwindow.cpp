#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    applyTransform();
    this->setStyleSheet("background: black");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::applyTransform()
{

    /*QPixmap * mypix = new QPixmap("../images/dot_and_needle.png");
    ui->RPM_needle->setPixmap(*mypix);

    QMatrix rm;
    rm.rotate(30);
    *mypix = mypix->transformed(rm);
    ui->RPM_needle->setPixmap(*mypix);*/
}
