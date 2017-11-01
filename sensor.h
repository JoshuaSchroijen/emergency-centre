#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <string>
#include <memory>
#include <list>

class GeneralSensorObserver;

#include "alarm.h"

class Sensor {
    private:
        int sensorID;
        bool activated;
        std::string sensorVendor;

        std::list < std::shared_ptr < Alarm > > alarms;

    public:
        Sensor ( int initialSensorID, bool initialState, std::string vendor );

        int getSensorID ( ) const;
        bool getActivated ( ) const;
        std::string getSensorVendor ( ) const;
        void setSensorID ( int newSensorID );
        void setActivated ( bool newState );
        void setSensorVendor ( std::string newSensorVendor );

        void addAlarm ( std::shared_ptr < Alarm > newAlarm );
        void deleteAlarm ( std::shared_ptr < Alarm > alarmToRemove );

        bool operator== ( const Sensor & otherSensor ) const;

        friend std::ostream & operator<< ( std::ostream & stream, const Sensor & sensor );

        virtual std::string getInformation ( ) const;
        virtual void observeAndReact ( const GeneralSensorObserver & observer ) = 0;
};

#endif
