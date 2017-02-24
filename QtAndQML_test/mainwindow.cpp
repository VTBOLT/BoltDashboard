#include <QQuickView>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createQuickWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createQuickWidget()
{
    QQuickView *view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    container->setMinimumSize(200, 200);
    container->setMaximumSize(200, 200);
    container->setFocusPolicy(Qt::TabFocus);
    // of course dont hard code this later ...
    view->setSource(QUrl("/home/sam/BoltDashboard/QtAndQML_test/main.qml"));
    ui->verticalLayout->addWidget(container);
}
