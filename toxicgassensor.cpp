#include "toxicgassensor.h"

#include "generalsensorobserver.h"

ToxicGasSensor::ToxicGasSensor ( std::string initialName, int initialSensorID, bool initialState, std::string initialVendor, int initialThresholdConcentration, GasType initialGasType ) :
    Sensor ( initialName, initialSensorID, initialState, initialVendor ),
    thresholdConcentration ( initialThresholdConcentration ),
    sensorGasType ( initialGasType ) {
}

GasType ToxicGasSensor::getGasType ( ) const {
   return ( sensorGasType );
}

int ToxicGasSensor::getThresholdConcentration ( ) const {
    return ( thresholdConcentration );
}

void ToxicGasSensor::setThresholdConcentration ( int newThresholdConcentration ) {
    thresholdConcentration = newThresholdConcentration;
}

void ToxicGasSensor::setGasType ( GasType newGasType ) {
    sensorGasType = newGasType;
}

std::string ToxicGasSensor::getOriginString ( ) const {
    return ( "Toxic gas sensor with ID " + std::to_string ( ID ) );
}

std::string ToxicGasSensor::getInformation ( int indentLevel ) const {
    std::string informationString = Sensor::getInformation ( indentLevel );
    informationString.replace ( indentLevel , 6, "Toxic gas sensor" );
    return ( informationString );
}

void ToxicGasSensor::observeAndReact ( const GeneralSensorObserver & observer ) const {
    if ( observer.observe ( this ) == true ) {
        for ( std::shared_ptr < Alarm > currentAlarm : alarms ) {
            ( * currentAlarm ) ( getOriginString ( ) );
        }
    }
}

