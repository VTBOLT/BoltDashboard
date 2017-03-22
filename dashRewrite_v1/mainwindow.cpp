/* AUTO GENERATED FILE  - has been updated*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_startup.h"



QTextStream qCout(stdout);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    gui(new Ui::MainWindow)
{
    gui->setupUi(this);

//    startup->c
//    startup->startup_label->setPixMap(startup_image);
//    delete startup_image;
    // show start up steps here ???

    // ??

    // instantiate the UI defined in Qt Creator

    // load QML for race view from source
    loadQML();
    // instantiate the can thread
    can = new InterfaceCan;
    // connect can signals to debug view
    connectDebugSlots();
    // connect 'clicked' signals to button actions
    connectNavSlots();
    // connect signals from can to race view
    connectRaceSlots();
    connectStartupSlots();
    // spin off the can thread
    can->start();
 }

MainWindow::~MainWindow()
{
    delete gui;
}

void MainWindow::loadQML()
{
    gui->qmlRace->setSource(QUrl("../dashRewrite_v1/Race_view.qml"));
}

void MainWindow::connectDebugSlots()
{
    // signals comes in from 'can' object, calls slot implemented in UI
    connect(can, SIGNAL( updateRPM(double)), gui->rpm_lcd,SLOT(display(double)));
    connect(can, SIGNAL( updateBatteryTemp(int)), gui->battTemp_lcd,SLOT(display(int)));
    connect(can, SIGNAL( updateRMScurr(int)), gui->rms_lcd,SLOT(display(int)));
    connect(can, SIGNAL( updateDCvolt(double)), gui->dc_lcd,SLOT(display(double)));
    connect(can, SIGNAL( updateHStemp(int)), gui->hs_lcd,SLOT(display(int)));
    connect(can, SIGNAL( updateMotorTemp(int)), gui->motorTemp_lcd,SLOT(display(int)));
    connect(can, SIGNAL( updateVoltAngle(int)), gui->angle_lcd,SLOT(display(int)));
    connect(can, SIGNAL( updateIQcurr(int)), gui->iq_lcd,SLOT(display(int)));
    connect(can, SIGNAL( sendEMCY6(int)), gui->emcy6_lcd,SLOT(display(int)));
    connect(can, SIGNAL( sendEMCY7(int)), gui->emcy7_lcd,SLOT(display(int)));
    connect(can, SIGNAL( sendD6stat(int)), gui->drive6_lcd,SLOT(display(int)));
    connect(can, SIGNAL( sendD7stat(int)), gui->drive7_lcd,SLOT(display(int)));
}

void MainWindow::connectRaceSlots()
{
    //QObject * qmlObject = ui->qmlRace->rootObject();
    //connect(can, SIGNAL(updateRPM_QVar(QVariant)), qmlObject, SLOT(qmlSlot(QVariant)));
    // set text for testing purposes only
    connect(can, SIGNAL(updateRPM_QVar(QVariant)), this, SLOT(setRPM(QVariant)));
    connect(can, SIGNAL(updateDCVolt_QVar(QVariant)), this, SLOT(setBatteryPercent(QVariant)));
}

void MainWindow::connectStartupSlots()
{
    connect(gui->step1, SIGNAL(clicked(bool)), this, SLOT(showStartupOne()));
    connect(gui->step2, SIGNAL(clicked(bool)), this, SLOT(showStartupTwo()));
    connect(gui->step3, SIGNAL(clicked(bool)), this, SLOT(showStartupThree()));
    connect(gui->startupToRace, SIGNAL(clicked(bool)), this, SLOT(toRaceView()));
    connect(gui->startupToDebug, SIGNAL(clicked(bool)), this, SLOT(toDebugView()));
}

void MainWindow::setRPM(QVariant rpm)
{
    QObject * rootObject = gui->qmlRace->rootObject();
    float angle = rpm.toFloat() * (180.0/8000.0);
    rootObject->setProperty("myRot", QVariant(angle));
}

void MainWindow::setBatteryPercent(QVariant value)
{
    QObject * rootObject = gui->qmlRace->rootObject();
    // convert value to a percentage of the rectangle's width...
    rootObject->setProperty("green_bar", QVariant(value));
}

void MainWindow::connectNavSlots()
{
    QObject * qmlObject = gui->qmlRace->rootObject();
    //connect(ui->toDebugButton,SIGNAL(clicked(bool)),this,SLOT(toDebugView()));
    connect(qmlObject, SIGNAL(toDebugSignal()), this, SLOT(toDebugView()));
    connect(gui->toRaceButton,SIGNAL(clicked(bool)),this,SLOT(toRaceView()));
}

void MainWindow::toDebugView()
{
    gui->views->setCurrentIndex(DEBUG);
}

void MainWindow::toRaceView()
{
    gui->views->setCurrentIndex(RACE);
}

void MainWindow::toStartupScreen()
{
    gui->views->setCurrentIndex(STARTUP);
}

void MainWindow::showStartupZero()
{
    setStyleSheet("background-image:url(:/images/startup_0.png);" );
}

void MainWindow::showStartupOne()
{
    setStyleSheet("background-image:url(:/images/startup_1.png)");
}

void MainWindow::showStartupTwo()
{
    setStyleSheet("background-image:url(:/images/startup_2.png)");
}

void MainWindow::showStartupThree()
{
    setStyleSheet("background-image:url(:/images/startup_3.png)");

}
