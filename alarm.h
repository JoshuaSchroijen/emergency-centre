#ifndef ALARM_H
#define ALARM_H


class alarm
{
public:
    alarm(int alarmID);
    int alarmId;
    virtual void ring() = 0;
    void setAlarmId(int newAlarmID);
    int getAlarmId();



};

#endif // ALARM_H
