#include "sensorinterface.h"

SensorInterface::SensorInterface ( std::string initialName, bool initialState ) :
    name ( initialName ), activated ( initialState )  {
}

std::string SensorInterface::getName ( ) {
    return  ( name );
}

bool SensorInterface::getActivated ( ) {
    return ( activated );
}

int SensorInterface::getID ( ) {
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
