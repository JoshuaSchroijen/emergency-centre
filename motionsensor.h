#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include <string>

class GeneralSensorObserver;

#include "sensor.h"

class MotionSensor : public Sensor {
    private:
        double minDistance;
        double maxDistance;

    public:
        MotionSensor ( ) : Sensor ( ), minDistance ( 0 ), maxDistance ( 0 ) { }
        MotionSensor ( std::string initialName, int initialSensorID, bool initialState, std::string initialVendor, double initialMinDistance, double initialMaxDistance );

        double getMinDistance ( );
        double getMaxDistance ( );
        void setMinDistance ( double newMinDistance );
        void setMaxDistance ( double newMaxDistance );

        std::string getInformation ( int indentLevel ) const override;
        std::string getOriginString ( ) const override;
        void observeAndReact ( const GeneralSensorObserver & observer ) const;
};

#endif
