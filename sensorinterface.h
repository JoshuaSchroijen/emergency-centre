#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include <string>

class SensorInterface {
    protected:
        std::string name;
        int ID;
        bool activated;

    public:
        SensorInterface ( std::string name , bool initialState );

        std::string getName ( );
        bool getActivated ( );
        int getID ( );
        void setName ( std::string newName );
        void setActivated ( bool newState );
        void setID ( int newID );
};

#endif
