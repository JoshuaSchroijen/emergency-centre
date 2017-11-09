#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include <string>

class SensorInterface {
    protected:
        std::string name;
        int ID;
        bool activated;

    public:
        SensorInterface ( ) : name ( "" ), ID ( 0 ), activated ( true ) { }
        SensorInterface ( std::string initialName, int initialID, bool initialState );

        std::string getName ( ) const;
        bool getActivated ( ) const;
        int getID ( ) const;
        void setName ( std::string newName );
        void setActivated ( bool newState );
        void setID ( int newID );

        virtual std::string getInformation ( int indentLevel ) const = 0;
};

#endif
