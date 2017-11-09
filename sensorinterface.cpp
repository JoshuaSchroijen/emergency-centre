#include "sensorinterface.h"

SensorInterface::SensorInterface ( std::string initialName, int initialID, bool initialState ) :
    name ( initialName ), ID ( initialID ), activated ( initialState )  {
}

std::string SensorInterface::getName ( ) const {
    return  ( name );
}

bool SensorInterface::getActivated ( ) const {
    return ( activated );
}

int SensorInterface::getID ( ) const {
    return ( ID );
}

void SensorInterface::setName ( std::string newName ) {
    name = newName;
}

void SensorInterface::setActivated ( bool newState ) {
    activated = newState;
}

void SensorInterface::setID ( int newID ) {
    ID = newID;
}
