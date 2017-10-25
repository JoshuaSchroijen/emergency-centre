#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include "alarm.h"
#include<vector>

class sensor
{
public:
    //attribut
    bool activated;
    int sensorID;
    std::vector<alarm> Alarms;
   //method
    sensor(int asensorID,bool aactivated);
    bool detection();
    int getSensorID();
    bool getActivated();
    void setSensorID (int newSensorID);
    void setActivated(bool newState);
    //virtual std::string getInformation();



};

#endif // SENSOR_H
