#include "sensorinterface.h"

SensorInterface::SensorInterface ( std::string name ) :
    SensorInterface::name ( name ) {
}


std::string SensorInterface::getName ( ) {
    return  ( SensorInterface::name );
}
