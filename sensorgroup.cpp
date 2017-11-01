#include "sensorinterface.h"
#include "sensorgroup.h"

SensorGroup::SensorGroup ( std::string sensorGroupName, bool initialState ) :
    SensorInterface ( sensorGroupName, initialState ) {
}

std::list < SensorInterface > & SensorGroup::getChildren ( ) {
    return ( SensorGroup::children );
}

void SensorGroup::addChild ( SensorInterface & newChild ) {
    children.push_back ( newChild );
}

void SensorGroup::addChildren ( std::list < SensorInterface > & newChildren ) {
    for ( SensorInterface currentNewChild : newChildren ) {
        children.push_back ( currentNewChild );
    }
}
