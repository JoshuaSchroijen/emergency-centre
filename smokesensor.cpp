#include "smokesensor.h"
#include <iostream>
#include <sstream>
smokesensor::smokesensor(int asensorID,bool aactivated,double asensitivity):sensor(asensorID, aactivated),sensitivity{asensitivity}
{

}
