#include "smokesensor.h"

SmokeSensor::SmokeSensor ( std::string initialName, int initialSensorID, bool initialState, std::string initialVendor, double initialSensitivity ) :
    Sensor ( initialName, initialSensorID, initialState, initialVendor ),
    sensitivity ( initialSensitivity ) {
}

double SmokeSensor::getSensitivity ( ) {
    return ( sensitivity );
}

void SmokeSensor::setSensitivity ( double newSensitivity ) {
    sensitivity = newSensitivity;
}

std::string SmokeSensor::getInformation ( int indentLevel ) const {
    std::string informationString = Sensor::getInformation ( indentLevel );
    informationString.replace ( indentLevel, 6, "Smoke sensor" );
    return ( informationString );
}

void SmokeSensor::observeAndReact ( const GeneralSensorObserver & observer ) {
    std::cout << "observe\n";
}
