#ifndef GENERALSENSOROBSERVER_H
#define GENERALSENSOROBSERVER_H

#include "sensor.h"

class GeneralSensorObserver {
    public:
    GeneralSensorObserver ( );

        virtual bool observe ( const Sensor * const sensor ) const = 0;
};

#endif
