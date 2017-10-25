#ifndef EVACUATIONALARM_H
#define EVACUATIONALARM_H
#include "alarm.h"

class evacuationalarm : public alarm
{
public:
    evacuationalarm(int alarmID);
     void ring();
     int alarmId;
};

#endif // EVACUATIONALARM_H
