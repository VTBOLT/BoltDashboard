#include "rosprocess.h"

/*
 * GOAL:::
 *  Instantiate the QProcess pointing at the ROS executable
 *  When data become available from the process's stdout
 *  - or - when an error comes from the stderr, we want to
 *  interpret the message subject and value, then set a variable,
 *  and finally emit a signal from this thread to the main UI thread
 *
 *
 *  I made this a little complicated... we are starting a Qprocess from
 *  within a QThread. We are doing this because you cannot emit Qt signals
 *  from ROS code. This allows is to pull data from the ROS process then
 *  send that data to the UI itself.
*/


/*
 * DATA PARSING SCHEME :::
 *  normal CAN data to be sent out of the ROS process via
 *  stdout (...cout).
 *  format CAN stdout messages as: <CAN ID>;<CAN DATA>
 *
 *  CAN error messages to be sent over stderr from
 *  the ROS process. These are collected and parsed by
 *  a separate function.
 *  format CAN stderr messages as <ERROR ID>;<ERROR DATA>;<ERROR MESSAGE>
*/

// MESSAGE ID's --- consider putting these into a shared header file
#define RPM 0
// END ID's

RosProcess::RosProcess(QString path, QStringList args)
{
    m_processObj = new QProcess();
    m_processObj->setProgram(path);
    m_processObj->setArguments(args);

    // when data become available on stdout of the process, get the data
    connect(m_processObj,SIGNAL(readyReadStandardOutput()),this,SLOT(readData()));

    // look for info passed on stderr
    connect(m_processObj,SIGNAL(readyReadStandardError()),this,SLOT(readError()));
}

void RosProcess::readData()
{
    QByteArray data = m_processObj->readAllStandardOutput();
    // Now we parse the data and emit a signal ...
}

void RosProcess::readError()
{
    QByteArray data = m_processObj->readAllStandardError();
    // parse the data and take an action based on the error code...
}

void RosProcess::parseData()
{
    // TODO
}

void RosProcess::parseError()
{
    // TODO
}

void RosProcess::run()
{
    // thread's main loop
    // put the code in an  infinite while loop
    // then just let it spin
    m_processObj->start();
}
