#ifndef SENSORGROUP_H
#define SENSORGROUP_H

#include <string>
#include <list>

#include "sensorinterface.h"

class SensorGroup : public SensorInterface {
    private:
        std::list < SensorInterface > children;

    public:
        SensorGroup ( std::string sensorGroupName );

        std::list < SensorInterface > getChildren ( );

        SensorInterface & getChildWithName ( std::string childName );

        void addChildren ( const SensorInterface & newChildren );
        void setActivated ( bool newActivationState );

        bool detection ( );
};

#endif // SENSORGROUP_H
