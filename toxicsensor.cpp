#include "toxicsensor.h"

toxicsensor::toxicsensor(int asensorID,bool aactivated, Gastype aGasType):sensor(asensorID, aactivated),gasType{aGasType}
{

}

void toxicsensor::setGasType(Gastype type)
{
    gasType=type;
}

Gastype toxicsensor::getGasType() const
{
   return gasType;
}


