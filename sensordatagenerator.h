#ifndef SENSORDATAGENERATOR_H
#define SENSORDATAGENERATOR_H

#include <memory>
#include <list>

#include "sensor.h"

class SensorDataGenerator {
    public:
        std::list < std::shared_ptr < Sensor > > subscribedSensors;

        void subscribeSensor ( std::shared_ptr < Sensor > newSensor );
        void unsubscribeSensor ( std::shared_ptr < Sensor > sensorToRemove );

        virtual void generateData ( ) = 0;
};

#endif
