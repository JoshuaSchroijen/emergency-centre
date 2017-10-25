#include "motionsensor.h"
#include <iostream>
#include <sstream>

motionSensor::motionSensor(int asensorID,bool aactivated ,double minDis,  double maxDis): sensor(asensorID, aactivated),minDistance{minDis},maxDistance{maxDis}
{

}

double motionSensor::getMaxDistance()
{
    return maxDistance;
}
double motionSensor::getMinDistance()
{
    return minDistance;
}

void motionSensor::setMinDistance(double newMinDistance)
{
    minDistance=newMinDistance;
}

void motionSensor::setMaxDistance(double newMaxDistance){

    maxDistance=newMaxDistance;
}

