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
        MotionSensor ( int initialSensorID, bool initialState, std::string initialVendor, double initialMinDistance, double initialMaxDistance );

        double getMinDistance ( );
        double getMaxDistance ( );
        void setMinDistance ( double newMinDistance );
        void setMaxDistance ( double newMaxDistance );

        std::string getInformation ( );
        void observeAndReact ( const GeneralSensorObserver & observer );
};

#endif
