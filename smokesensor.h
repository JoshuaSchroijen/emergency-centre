#ifndef SMOKESENSOR_H
#define SMOKESENSOR_H

#include <string>

class GeneralSensorObserver;

#include "sensor.h"

class SmokeSensor : public Sensor {
    private:
        double sensitivity;

    public:
        SmokeSensor ( int initialSensorID, bool initialState, std::string initialVendor, double initialSensitivity );

        double getSensitivity ( );
        void setSensitivity ( double newSensitivity );

        std::string getInformation ( );
        void observeAndReact ( const GeneralSensorObserver & observer );
};

#endif
