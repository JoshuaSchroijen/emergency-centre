#include "motionsensor.h"

MotionSensor::MotionSensor ( int initialSensorID, bool initialState, std::string initialVendor, double initialMinDistance, double initialMaxDistance ) :
    Sensor ( initialSensorID, initialState, initialVendor ),
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

std::string MotionSensor::getInformation ( ) {
    std::string informationString = Sensor::getInformation ( );
    informationString.replace ( 0, 6, "Motion sensor" );
    return ( informationString );
}

void MotionSensor::observeAndReact ( const GeneralSensorObserver & observer ) {
    std::cout << "observe\n";
}
