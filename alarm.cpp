#include "alarm.h"
#include <iostream>
#include <sstream>

alarm::alarm(int alarmid):alarmId{alarmid}
{

}
int alarm::getAlarmId(){

    return alarmId;
}

void alarm::setAlarmId(int newAlarmID){

    alarmId=newAlarmID;
}

