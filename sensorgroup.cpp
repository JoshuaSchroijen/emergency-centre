#include "sensorinterface.h"
#include "sensorgroup.h"

SensorGroup::SensorGroup ( std::string sensorGroupName, int initialGroupID, bool initialState ) :
    SensorInterface ( sensorGroupName, initialGroupID, initialState ) {
}

const std::list < std::shared_ptr < SensorInterface > > & SensorGroup::getChildren ( ) {
    return ( SensorGroup::children );
}

void SensorGroup::addChild ( const SensorInterface & newChild ) {
    children.push_back ( std::shared_ptr < SensorInterface > ( ( ( SensorInterface * const ) & newChild ) ) );
}

void SensorGroup::addChild ( const SensorInterface * newChild ) {
    children.push_back ( std::shared_ptr < SensorInterface > ( const_cast < SensorInterface * > ( newChild ) ) );
}

void SensorGroup::addChild ( const std::shared_ptr < SensorInterface > & newChild ) {
    children.push_back ( newChild );
}

void SensorGroup::addChildren ( const std::list < std::shared_ptr < SensorInterface > > & newChildren ) {
    for ( std::shared_ptr < SensorInterface > currentNewChild : newChildren ) {
        children.push_back ( currentNewChild );
    }
}

unsigned int SensorGroup::getNumberOfChildren ( ) {
    return ( children.size ( ) );
}

const std::shared_ptr < SensorInterface > & SensorGroup::getChildAt ( const int childIndex ) {
    if ( childIndex < 0 ) {
        return ( * ( children.begin ( ) ) );
    } else if ( ( ( unsigned int ) childIndex ) >= children.size ( ) ) {
        return ( * ( children.end ( ) ) );
    } else {
        std::list < std::shared_ptr < SensorInterface > >::iterator childFinder = children.begin ( );
        int currentIndex = 0;
        while ( currentIndex != childIndex ) {
            currentIndex++;
            childFinder++;
        }
        return ( * ( childFinder ) );
    }
}

void SensorGroup::sortChildren ( ) {
    for ( std::shared_ptr < SensorInterface > currentChild : children ) {
        if ( SensorGroup * currentChildGroup = dynamic_cast < SensorGroup * > ( currentChild.get ( ) ) ) {
            currentChildGroup->sortChildren ( );
        }
    }
    children.sort ( );
}

std::string SensorGroup::getInformation ( int indentLevel ) const {
    std::string severalTabs = std::string ( indentLevel, '\t' );
    std::string informationString = ( severalTabs + "Sensor group " + name + ":\n" );

    for ( const std::shared_ptr < SensorInterface > & currentChild : children ) {
        informationString += currentChild->getInformation ( ( indentLevel + 1 ) );
    }

    return ( informationString );
}

std::ostream & operator<< ( std::ostream & stream, const SensorGroup & sensorGroup ) {
    stream << sensorGroup.getInformation ( 0 );
    return ( stream );
}
