#include "motionsensor.h"

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

std::string MotionSensor::getInformation ( int indentLevel ) const {
    std::string informationString = Sensor::getInformation ( indentLevel );
    informationString.replace ( indentLevel, 6, "Motion sensor" );
    return ( informationString );
}

void MotionSensor::observeAndReact ( const GeneralSensorObserver & observer ) {
    std::cout << "observe\n";
}
