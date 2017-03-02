/* AUTO GENERATED FILE  - has been updated*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // instantiate the UI defined in Qt Creator
    ui->setupUi(this);
    // instantiate the can thread
    can = new InterfaceCan;
    // connect can signals to debug view
    connectDebugSlots();
    // connect 'clicked' signals to button actions
    connectNavSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectDebugSlots()
{
    // signals comes in from 'can' object, calls slot implemented in UI
    connect(can, SIGNAL( updateRPM(double)), ui->rpm_lcd,SLOT(display(double)));
    connect(can, SIGNAL( updateBatteryTemp(int)), ui->battTemp_lcd,SLOT(display(int)));
    connect(can, SIGNAL( updateRMScurr(int)), ui->rms_lcd,SLOT(display(int)));
    connect(can, SIGNAL( updateDCvolt(double)), ui->dc_lcd,SLOT(display(double)));
    connect(can, SIGNAL( updateHStemp(int)), ui->hs_lcd,SLOT(display(int)));
    connect(can, SIGNAL( updateMotorTemp(int)), ui->motorTemp_lcd,SLOT(display(int)));
    connect(can, SIGNAL( updateVoltAngle(int)), ui->angle_lcd,SLOT(display(int)));
    connect(can, SIGNAL( updateIQcurr(int)), ui->iq_lcd,SLOT(display(int)));
    connect(can, SIGNAL( sendEMCY6(int)), ui->emcy6_lcd,SLOT(display(int)));
    connect(can, SIGNAL( sendEMCY7(int)), ui->emcy7_lcd,SLOT(display(int)));
    connect(can, SIGNAL( sendD6stat(int)), ui->drive6_lcd,SLOT(display(int)));
    connect(can, SIGNAL( sendD7stat(int)), ui->drive7_lcd,SLOT(display(int)));
}

void MainWindow::connectRaceSlots()
{
    // not yet implemented...
}

void MainWindow::connectNavSlots()
{
    connect(ui->toDebugButton,SIGNAL(clicked(bool)),this,SLOT(toDebugView()));
    connect(ui->toRaceButton,SIGNAL(clicked(bool)),this,SLOT(toRaceView()));
}

void MainWindow::toDebugView()
{
    ui->views->setCurrentIndex(DEBUG);
}

void MainWindow::toRaceView()
{
    ui->views->setCurrentIndex(RACE);
}
