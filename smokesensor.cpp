#include "smokesensor.h"
#include <iostream>
#include <sstream>
smokesensor::smokesensor(int asensorID,bool aactivated,double asensitivity):sensor(asensorID, aactivated),sensitivity{asensitivity}
{

}

double smokesensor::getSensitivity()
{
    return sensitivity;
}

void smokesensor::setSensitivity(double newSensitivity)
{
    sensitivity=newSensitivity;
}
