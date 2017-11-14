#include "smokesensor.h"

#include "generalsensorobserver.h"
#include "sensorobserver.hpp"

SmokeSensor::SmokeSensor ( std::string initialName, int initialSensorID, bool initialState, std::string initialVendor, double initialSensitivity ) :
    Sensor ( initialName, initialSensorID, initialState, initialVendor ),
    sensitivity ( initialSensitivity ) {
}

double SmokeSensor::getSensitivity ( ) const {
    return ( sensitivity );
}

void SmokeSensor::setSensitivity ( double newSensitivity ) {
    sensitivity = newSensitivity;
}

std::string SmokeSensor::getOriginString ( ) const {
    return ( "Smoke sensor with ID " + std::to_string ( ID ) );
}

std::string SmokeSensor::getInformation ( int indentLevel ) const {
    std::string informationString = Sensor::getInformation ( indentLevel );
    informationString.replace ( indentLevel, 6, "Smoke sensor" );
    return ( informationString );
}

void SmokeSensor::observeAndReact ( const GeneralSensorObserver * const observer ) const {
    if ( const SensorObserver < double > * const concreteObserver = dynamic_cast < const SensorObserver < double > * const > ( observer ) ) {
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
