/* AUTO GENERATED FILE - has been modified */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// 'page' numbers
#define STARTUP 0
#define RACE    1
#define DEBUG   2

#include <QMainWindow>
#include <QWidget>
#include <QUrl>
#include <QQuickItem>
#include <QTextStream>
#include "interfacecan.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void showStartup();
    ~MainWindow();

private:
    Ui::MainWindow *gui;
    InterfaceCan * can;

    void loadQML();

    void connectDebugSlots();
    void connectRaceSlots();
    void connectNavSlots();
    void connectStartupSlots();


private slots:
    void setRPM(QVariant rpm);
    void toDebugView();
    void toStartupScreen();
    void toRaceView();
    void setBatteryPercent(QVariant value);
    void showStartupZero();
    void showStartupOne();
    void showStartupTwo();
    void showStartupThree();
};

#endif // MAINWINDOW_H
