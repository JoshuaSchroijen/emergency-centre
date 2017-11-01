#ifndef SENSORGROUP_H
#define SENSORGROUP_H

#include <string>
#include <list>
#include <memory>

#include "sensorinterface.h"

class SensorGroup : public SensorInterface {
    private:
        std::list < SensorInterface > children;

    public:
        SensorGroup ( std::string sensorGroupName, bool initialState );

        std::list < SensorInterface > & getChildren ( );

        void addChild ( SensorInterface & newChild );
        void addChildren ( std::list < SensorInterface > & newChildren );
};

#endif
