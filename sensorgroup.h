#ifndef SENSORGROUP_H
#define SENSORGROUP_H

#include <string>
#include <list>
#include <memory>

#include "sensorinterface.h"

class SensorGroup : public SensorInterface {
    private:
        std::list < std::shared_ptr < SensorInterface > > children;

    public:
        SensorGroup ( std::string sensorGroupName, int initialGroupID, bool initialState );

        void addChild ( const SensorInterface & newChild );
        void addChild ( const SensorInterface * newChild );
        void addChildren ( const std::list < std::shared_ptr < SensorInterface > > & newChildren );
        unsigned int getNumberOfChildren ( );
        const std::list < std::shared_ptr < SensorInterface > > & getChildren ( );
        const std::shared_ptr < SensorInterface > & getChildAt ( const int childIndex );
        void sortChildren ( );

        friend std::ostream & operator<< ( std::ostream & stream, const SensorGroup & sensorGroup );

        std::string getInformation (int indentLevel) const override;
};

#endif
