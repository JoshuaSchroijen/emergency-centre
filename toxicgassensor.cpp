#include "toxicgassensor.h"

ToxicGasSensor::ToxicGasSensor ( std::string initialName, int initialSensorID, bool initialState, std::string initialVendor, GasType initialGasType ) :
    Sensor ( initialName, initialSensorID, initialState, initialVendor ),
    sensorGasType ( initialGasType ) {
}

GasType ToxicGasSensor::getGasType ( ) const {
   return ( sensorGasType );
}

void ToxicGasSensor::setGasType ( GasType newGasType ) {
    sensorGasType = newGasType;
}

std::string ToxicGasSensor::getInformation ( int indentLevel ) const {
    std::string informationString = Sensor::getInformation ( indentLevel );
    informationString.replace ( indentLevel , 6, "Toxic gas sensor" );
    return ( informationString );
}

void ToxicGasSensor::observeAndReact ( const GeneralSensorObserver & observer ) {
    std::cout << "observe\n";
}

