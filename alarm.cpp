#include "alarm.h"
#include <iostream>
#include <sstream>

alarm::alarm(int alarmID):alarm{alarmID}
{

}
int alarm::getAlarmId(){

    return alarmId;
}

void alarm::setAlarmId(int newAlarmID){

    alarmId=newAlarmID;
}

