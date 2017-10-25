#ifndef TOXICSENSOR_H
#define TOXICSENSOR_H
#include "sensor.h"

enum Gastype{octane,methane,butane};
class toxicsensor : public sensor
{
public:
    //method
    toxicsensor();
    toxicsensor(int asensorID,bool aactivated ,Gastype aGasType=octane);
    void setGasType(enum Gastype);
    Gastype getGasType()const;
    //attributr
 private:
    Gastype gasType ;

};

#endif // TOXICSENSOR_H
