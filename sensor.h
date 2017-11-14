#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <string>
#include <memory>
#include <list>

class GeneralSensorObserver;
class SensorGroup;

#include "sensorinterface.h"
#include "alarm.h"

class Sensor : public SensorInterface {
    protected:
        int getSensorType ( ) const;

        std::string sensorVendor;

        std::list < std::shared_ptr < Alarm > > alarms;

    public:
        Sensor ( ) : SensorInterface ( "", 0, true ), sensorVendor ( "" ) { }
        Sensor ( std::string initialName, int initialSensorID, bool initialState, std::string vendor );

        std::string getSensorVendor ( ) const;
        void setSensorVendor ( std::string newSensorVendor );

        void addAlarm ( std::shared_ptr < Alarm > newAlarm );
        void deleteAlarm ( std::shared_ptr < Alarm > alarmToRemove );

        bool operator== ( const Sensor & otherSensor ) const;
        bool operator< ( const Sensor & other ) const;
        bool operator< ( const SensorGroup & sensorGroup ) const;
        Sensor & operator++ ( );
        Sensor & operator-- ( );

        friend std::ostream & operator<< ( std::ostream & stream, const Sensor & sensor );

        virtual std::string getInformation ( int indentLevel ) const override;
        virtual std::string getOriginString ( ) const = 0;
        virtual void observeAndReact ( const GeneralSensorObserver * const observer ) const = 0;
};

#endif
