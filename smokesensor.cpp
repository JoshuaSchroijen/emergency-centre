#include "smokesensor.h"

SmokeSensor::SmokeSensor ( int initialSensorID, bool initialState, std::string initialVendor, double initialSensitivity ) :
    Sensor ( initialSensorID, initialState, initialVendor ),
    sensitivity ( initialSensitivity ) {
}

double SmokeSensor::getSensitivity ( ) {
    return ( sensitivity );
}

void SmokeSensor::setSensitivity ( double newSensitivity ) {
    sensitivity = newSensitivity;
}

std::string SmokeSensor::getInformation ( ) {
    std::string informationString = Sensor::getInformation ( );
    informationString.replace ( 0, 6, "Smoke sensor" );
    return ( informationString );
}

void SmokeSensor::observeAndReact ( const GeneralSensorObserver & observer ) {
    std::cout << "observe\n";
}
