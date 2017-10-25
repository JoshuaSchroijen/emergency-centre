#ifndef POLICEALARM_H
#define POLICEALARM_H
#include "alarm.h"

class policealarm :public alarm
{
public:
    policealarm(int alarmID);
     void ring();
    int alarmId;
};

#endif // POLICEALARM_H
