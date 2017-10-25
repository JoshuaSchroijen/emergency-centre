#ifndef SMOKESENSOR_H
#define SMOKESENSOR_H
#include "sensor.h"

class smokesensor : public sensor
{
public:
    //method

    smokesensor(int asensorID,bool aactivated,double asensitivity);
    double getSensitivity();
    void setSensitivity(double newSensitivity);

private:
   //attribut
    double sensitivity;
};

#endif // SMOKESENSOR_H
