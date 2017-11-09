#include <iostream>

#include "sensor.h"
#include "smokesensor.h"
#include "toxicgassensor.h"
#include "motionsensor.h"

int Sensor::getSensorType ( ) const {
    if ( dynamic_cast < const MotionSensor * > ( this ) ) {
        return ( 0 );
    } else if ( dynamic_cast < const SmokeSensor * > ( this ) ) {
        return ( 1 );
    } else if ( dynamic_cast < const ToxicGasSensor * > ( this ) ) {
        return ( 2 );
    } else {
        return ( -1 );
    }
}

Sensor::Sensor ( std::string initialName, int initialSensorID, bool initialState , std::string vendor ) :
    SensorInterface ( initialName, initialSensorID, initialState ),
    sensorVendor ( vendor ) {
}


std::string Sensor::getSensorVendor ( ) const {
    return ( sensorVendor );
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

std::string Sensor::getInformation ( int indentLevel ) const {
    std::string severalTabs = std::string ( indentLevel, '\t');
    std::string informationString ( severalTabs + "Sensor with ID " );
    informationString += std::to_string ( ID );
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
    return ( otherSensor.getID ( ) == ID );
}

std::ostream & operator<< ( std::ostream & stream, const Sensor & sensor ) {
    stream << sensor.getInformation ( 0 );
    return ( stream );
}

bool Sensor::operator< ( const Sensor & other ) const {
    if ( getSensorType ( ) < other.getSensorType ( ) ) {
        return ( true );
    } else if ( getSensorType ( ) == other.getSensorType ( ) ) {
        if ( sensorVendor < other.sensorVendor ) {
            return ( true );
        } else if ( sensorVendor == other.sensorVendor ) {
            if ( ID < other.ID ) {
                return ( true );
            } else {
                return ( false );
            }
        } else {
            return ( false );
        }
    } else {
        return ( false );
    }
}

bool Sensor::operator< ( const SensorGroup & sensorGroup ) const {
    return ( false );
}

Sensor & Sensor::operator++ ( ) {
    setActivated ( true );
    return ( * this );
}

Sensor & Sensor::operator-- ( ) {
    setActivated ( false );
    return ( * this );
}
