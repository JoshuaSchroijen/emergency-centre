#include "sensorinterface.h"
#include "sensorgroup.h"

SensorGroup::SensorGroup ( std::string sensorGroupName ) :
    SensorInterface ( sensorGroupName ) {
}

std::list < SensorInterface > SensorGroup::getChildren ( ) {
    return ( SensorGroup::children );
}

SensorInterface & SensorGroup::getChildWithName ( std::string childName ) {
    for ( SensorInterface & child : SensorGroup::children ) {
        if ( child.getName ( ) == childName ) {
            return ( child );
        }
    }
}

void SensorGroup::setActivated ( bool newActivationState ) {
    for ( SensorInterface & child : SensorGroup::children ) {
        child.setActivated ( newActivationState );
    }
}

void SensorGroup::addChildren ( const SensorInterface & newChildren ) {
    SensorGroup::children.push_back( newChildren );
}

void SensorGroup::detection ( ) {
    for ( SensorInterface & child : SensorGroup::children ) {
        child.detection ( );
    }
}
