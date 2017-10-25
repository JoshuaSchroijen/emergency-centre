#include "sensor.h"
#include <iostream>
#include <sstream>
sensor::sensor(int asensorID, bool aactivated):sensorID{asensorID}, activated{aactivated}
{

}

bool sensor::detection()
{
   if (activated==0) {

       return 0;
   }
   else{

       return 1;
   }
}

int sensor::getSensorID()
{
    return sensorID;
}

bool sensor::getActivated()
{
   return activated;
}

void sensor::setSensorID(int newSensorID)
{
    sensorID=newSensorID;
}

void sensor::setActivated(bool newState)
{
    activated=newState;
}



