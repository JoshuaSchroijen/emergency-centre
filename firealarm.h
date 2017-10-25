#ifndef FIREALARM_H
#define FIREALARM_H
#include "alarm.h"

class Firealarm : public alarm
{
public:
    Firealarm(int alarmID);
    void ring();
   // int alarmId;
};

#endif // FIREALARM_H
