#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H
#include "sensor.h"

class motionSensor : public sensor
{
public:
    //method

    motionSensor(int asensorID,bool aactivated ,double minDis, double maxDis);
    double getMinDistance ();
    double getMaxDistance();
    void setMaxDistance(double newMaxDistance);
    void setMinDistance(double newMinDistance);
 private: //attribut
    double minDistance;
    double maxDistance;

};

#endif // MOTIONSENSOR_H
