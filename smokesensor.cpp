#include "smokesensor.h"

#include "generalsensorobserver.h"

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

void SmokeSensor::observeAndReact ( const GeneralSensorObserver & observer ) const {
    if ( observer.observe ( this ) == true ) {
        for ( std::shared_ptr < Alarm > currentAlarm : alarms ) {
            ( * currentAlarm ) ( getOriginString ( ) );
        }
    }
}
