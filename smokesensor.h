#ifndef SMOKESENSOR_H
#define SMOKESENSOR_H

#include <string>

class GeneralSensorObserver;

#include "sensor.h"

class SmokeSensor : public Sensor {
    private:
        double sensitivity;

    public:
        SmokeSensor ( ) : Sensor ( ), sensitivity ( 0 ) { }
        SmokeSensor ( std::string initialName, int initialSensorID, bool initialState, std::string initialVendor, double initialSensitivity );

        double getSensitivity ( ) const;
        void setSensitivity ( double newSensitivity );

        std::string getInformation ( int indentLevel ) const override;
        std::string getOriginString ( ) const override;
        void observeAndReact ( const GeneralSensorObserver * const observer ) const;
};

#endif
