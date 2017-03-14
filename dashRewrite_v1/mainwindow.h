/* AUTO GENERATED FILE - has been modified */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// 'page' numbers
#define RACE    0
#define DEBUG   1

#include <QMainWindow>
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
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    InterfaceCan * can;

    void loadQML();

    void connectDebugSlots();
    void connectRaceSlots();
    void connectNavSlots();

private slots:
    void setRPM(QVariant text);
    void toDebugView();
    void toRaceView();
};

#endif // MAINWINDOW_H
