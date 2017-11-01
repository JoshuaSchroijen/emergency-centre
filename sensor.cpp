#include <iostream>

#include "sensor.h"

Sensor::Sensor ( int initialSensorID, bool initialState , std::string vendor ) :
    sensorID ( initialSensorID ),
    activated ( initialState ),
    sensorVendor ( vendor ) {
}

int Sensor::getSensorID ( ) const {
    return ( sensorID );
}

bool Sensor::getActivated ( ) const {
   return ( activated );
}

std::string Sensor::getSensorVendor ( ) const {
    return ( sensorVendor );
}

void Sensor::setSensorID ( int newSensorID ) {
    sensorID = newSensorID;
}

void Sensor::setActivated ( bool newState ) {
    activated = newState;
}

void Sensor::setSensorVendor ( std::string newSensorVendor ) {
    sensorVendor = newSensorVendor;
}


void Sensor::addAlarm ( std::shared_ptr < Alarm > newAlarm ) {
    alarms.push_back ( newAlarm );
}

void Sensor::deleteAlarm ( std::shared_ptr < Alarm > alarmToRemove ) {
    alarms.remove ( alarmToRemove );
}

std::string Sensor::getInformation ( ) const {
    std::string informationString ( "Sensor with ID " );
    informationString += std::to_string ( sensorID );
    informationString += ", from vendor ";
    informationString += sensorVendor;
    informationString += ". Status: ";

    if ( activated == true ) {
        informationString += "active.\n";
    } else {
        informationString += "disabled.\n";
    }

    return ( informationString );
}


bool Sensor::operator== ( const Sensor & otherSensor ) const {
    return ( otherSensor.getSensorID ( ) == sensorID );
}

std::ostream & operator<< ( std::ostream & stream, const Sensor & sensor ) {
    stream << sensor.getInformation ( );
    return ( stream );
}
