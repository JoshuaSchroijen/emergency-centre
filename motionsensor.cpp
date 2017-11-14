#include "motionsensor.h"

#include "generalsensorobserver.h"
#include "sensorobserver.hpp"

MotionSensor::MotionSensor ( std::string initialName, int initialSensorID, bool initialState, std::string initialVendor, double initialMinDistance, double initialMaxDistance ) :
    Sensor ( initialName, initialSensorID, initialState, initialVendor ),
    minDistance ( initialMinDistance ),
    maxDistance ( initialMaxDistance ) {
}

double MotionSensor::getMinDistance ( ) {
    return ( minDistance );
}

double MotionSensor::getMaxDistance ( ) {
    return ( maxDistance );
}

void MotionSensor::setMinDistance ( double newMinDistance ) {
    minDistance = newMinDistance;
}

void MotionSensor::setMaxDistance ( double newMaxDistance ) {
    maxDistance = newMaxDistance;
}

std::string MotionSensor::getOriginString ( ) const {
    return ( "Motion sensor with ID " + std::to_string ( ID ) );
}

std::string MotionSensor::getInformation ( int indentLevel ) const {
    std::string informationString = Sensor::getInformation ( indentLevel );
    informationString.replace ( indentLevel, 6, "Motion sensor" );
    return ( informationString );
}

void MotionSensor::observeAndReact ( const GeneralSensorObserver * const observer ) const {
    if ( const SensorObserver < bool > * const concreteObserver = dynamic_cast < const SensorObserver < bool > * const > ( observer ) ) {
        if ( concreteObserver->observe ( this ) == true ) {
            for ( std::shared_ptr < Alarm > currentAlarm : alarms ) {
                ( * currentAlarm ) ( getOriginString ( ) );
                std::cout << getOriginString ( ) + " registered value of "
                          << concreteObserver->getStoredDataElement ( )
                          << "\n";
            }
        }
    } else {
    }
}
