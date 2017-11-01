#include "toxicgassensor.h"

ToxicGasSensor::ToxicGasSensor ( int initialSensorID, bool initialState, std::string initialVendor, GasType initialGasType ) :
    Sensor ( initialSensorID, initialState, initialVendor ),
    sensorGasType ( initialGasType ) {
}

GasType ToxicGasSensor::getGasType ( ) const {
   return ( sensorGasType );
}

void ToxicGasSensor::setGasType ( GasType newGasType ) {
    sensorGasType = newGasType;
}

std::string ToxicGasSensor::getInformation ( ) {
    std::string informationString = Sensor::getInformation ( );
    informationString.replace ( 0, 6, "Toxic gas sensor" );
    return ( informationString );
}

void ToxicGasSensor::observeAndReact ( const GeneralSensorObserver & observer ) {
    std::cout << "observe\n";
}

