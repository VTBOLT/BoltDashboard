#include "interfacecan.h"
#include <unistd.h>

#include <QTextStream> // for testing only ...

QTextStream qtCout(stdout);

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

void InterfaceCan::run()
{
    float i = 0;
    float incr = -1;

    int dumb_counter = 0;
    double dcVolt = 515;

    while (1)
    {
        dumb_counter++;
        if (dumb_counter % 100 == 0 )
        {
            dumb_counter = 0;
            emit(updateDCvolt(dcVolt));
            emit(updateDCVolt_QVar(QVariant(dcVolt)));
            dcVolt = dcVolt -2;
            if(dcVolt < 0){
                dcVolt = 515;
            }
        }

        emit updateRPM(i);
        emit updateRPM_QVar(QVariant(i));
        if ( i > 7999 || i <= 0)
            incr = -1 * incr;
        i = i + incr;

        usleep(500);
    }

    //runCan();
}

void InterfaceCan::runCan() {
        //system("modprobe vcan");
        //system("ip link set vcan0 up type vcan bitrate 250000");
       //system("ifconfig vcan0 up");
        char* argv2[2];
        argv2[0] = " ";
        argv2[1] = "can0";
        struct canfd_frame message;
        struct sigaction siginthandler;
        siginthandler.sa_handler = my_handler;
        sigemptyset(&siginthandler.sa_mask);
        siginthandler.sa_flags=0;
        sigaction(SIGINT, &siginthandler, NULL);
        signed short batterytemp = 0;
        signed short rpm = 0;
        signed short RMS_current = 0;
        signed short DC_voltage = 0;
        signed short HS_temp = 0;
        signed short motor_temp = 0;
        signed short voltage_angle = 0;
        signed short IQ_current = 0;
        signed short EMCY6 = 0;
        signed short EMCY7 = 0;
        signed short drive6stat = 0;
        signed short drive7stat = 0;
        //time_t end = time(NULL) + 20;

        /*
         * PLAN:
         * instead of updating variables below,
         * they would be updated then sent as a SIGNAL to the main loop
         * where a widget could handle them. If unhandled, they would not do
         * any harm to the application
         */

        while (1)
        {
            message = canrecieve(2, argv2);
            if (message.len > 0)
            {
                switch(message.can_id)
                {
                    case 0x186:
                    {
                        rpm = (message.data[1] << 8 | message.data[0]);
                        emit updateRPM(rpm);
                        emit updateRPM_QVar( QVariant(rpm) );
                        RMS_current = (message.data[7] << 8 | message.data[6]);
                        emit updateRMScurr(RMS_current);
                        DC_voltage = (message.data[5] << 8 | message.data[4]);
                        emit updateDCvolt(DC_voltage/100.0);
                        drive6stat = (message.data[3] << 8 | message.data[2]);
                        emit sendD6stat(drive6stat);
                        break;
                    }
                    case 0x183:
                    {
                        batterytemp = (message.data[5] << 8 | message.data[4]);
                        emit updateBatteryTemp(batterytemp);
                        break;
                    }
                    case 0x286:
                    {
                        HS_temp = (message.data[1] << 8 | message.data[0]);
                        emit updateHStemp(HS_temp);
                        motor_temp = (message.data[3] << 8 | message.data[2]);
                        emit updateMotorTemp(motor_temp);
                        voltage_angle = (message.data[7] << 8 | message.data[6]);
                        emit updateVoltAngle(voltage_angle);
                        break;
                    }
                    case 0x386:
                    {
                        IQ_current = (message.data[1] << 8 | message.data[0]);
                        emit updateIQcurr(IQ_current);
                        break;
                    }
                    case 0x086:
                    {
                        EMCY6 = (message.data[1] << 8 | message.data[0]);
                        emit sendEMCY6(EMCY6);
                        break;
                    }
                    case 0x087:
                    {
                        EMCY7 = (message.data[1] << 8 | message.data[0]);
                        emit sendEMCY7(EMCY7);
                        break;
                    }
                    case 0x187:
                    {
                        drive7stat = (message.data[3] << 8 | message.data[2]);
                        emit sendD7stat(drive7stat);
                        break;
                    }
                    default: {}
                }
            }
            //else
            //{
            //   cout << "Recieved CAN Error" << endl;
            //   // Log and error here? otherwise do nothing...
            //}
        }
}

void my_handler(int s)
{
    exit(1);
}
