#ifndef SENSOROBSERVOR_H
#define SENSOROBSERVOR_H

#include "smokesensor.h"
#include "toxicgassensor.h"
#include "motionsensor.h"

#include "generalsensorobserver.h"

template < typename T >
class SensorObserver : public GeneralSensorObserver {
    private:
        T storedDataElement;
    public:
        SensorObserver ( );
        SensorObserver ( T initialDataElement );

        T getStoredDataElement ( ) const;
        void setStoredDataElement ( T newDataElement );

        bool observe ( const Sensor * const sensor ) const override;
};

template < typename T >
SensorObserver < T >::SensorObserver ( ) {
}

template < typename T >
SensorObserver < T >::SensorObserver ( T initialDataElement ) :
    storedDataElement ( initialDataElement ) {
}

template < typename T >
T SensorObserver < T >::getStoredDataElement ( ) const {
    return ( storedDataElement );
}

template < typename T >
void SensorObserver < T >::setStoredDataElement ( T newDataElement ) {
    storedDataElement = newDataElement;
}

template < typename T >
bool SensorObserver < T >::observe ( const Sensor * const sensor ) const {
    if ( const SmokeSensor * const smokeSensor = dynamic_cast < const SmokeSensor * const > ( sensor ) ) {
        if ( storedDataElement <= smokeSensor->getSensitivity ( ) ) {
            return ( true );
        } else {
            return ( false );
        }
    } else if ( const ToxicGasSensor * const toxicGasSensor = dynamic_cast < const ToxicGasSensor * const > ( sensor ) ) {
        if ( storedDataElement >= toxicGasSensor->getThresholdConcentration ( ) ) {
            return ( true );
        } else {
            return ( false );
        }
    } else if ( const MotionSensor * const motionSensor = dynamic_cast < const MotionSensor * const > ( sensor ) ) {
        if ( storedDataElement == true ) {
            return ( true );
        } else {
            return ( false );
        }
    } else {
        return ( false );
    }
}

#endif
