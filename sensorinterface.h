#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include <string>

class SensorInterface {
    protected:
        std::string name;

    public:
        SensorInterface ( std::string name );

        virtual std::string getName ( );
        virtual void setActivated ( bool newActivationState );
        virtual bool detection ( ) = 0;
};

#endif // SENSORINTERFACE_H
