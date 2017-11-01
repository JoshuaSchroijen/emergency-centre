#ifndef SENSOROBSERVOR_H
#define SENSOROBSERVOR_H

class SmokeSensor;
class ToxicGasSensor;
class MotionSensor;

#include "generalsensorobserver.h"

template < typename T >
class SensorObserver : public GeneralSensorObserver {
    private:
        T storedDataElement;
    public:
        SensorObserver ( );
        SensorObserver ( T initialDataElement );

        T getStoredDataElement ( );
        void setStoredDataElement ( T newDataElement );

        bool observe ( const SmokeSensor & smokeSensor);
        bool observe ( const ToxicGasSensor & toxicGasSensor );
        bool observe ( const MotionSensor & movementSensor);
};

template < typename T >
SensorObserver < T >::SensorObserver ( ) {
}

template < typename T >
SensorObserver < T >::SensorObserver ( T initialDataElement ) :
    storedDataElement ( initialDataElement ) {
}

template < typename T >
T SensorObserver < T >::getStoredDataElement ( ) {
    return ( storedDataElement );
}

template < typename T >
void SensorObserver < T >::setStoredDataElement ( T newDataElement ) {
    storedDataElement = newDataElement;
}

template < typename T >
bool SensorObserver < T >::observe ( const SmokeSensor & smokeSensor ) {
    return ( true );
}

template < typename T >
bool SensorObserver < T >::observe ( const ToxicGasSensor & toxicGasSensor ) {
    return ( true );
}

template < typename T >
bool SensorObserver < T >::observe ( const MotionSensor & movementSensor ) {
    return ( true );
}

#endif
