#ifndef TOXICSENSOR_H
#define TOXICSENSOR_H

#include <string>

class GeneralSensorObserver;

#include "sensor.h"

enum GasType { CarbonMonoxide };

class ToxicGasSensor : public Sensor {
    private:
        int thresholdConcentration;
        GasType sensorGasType;

    public:
        ToxicGasSensor ( ) : Sensor ( ), thresholdConcentration ( 0 ), sensorGasType ( CarbonMonoxide ) { }
        ToxicGasSensor ( std::string initialName, int initialSensorID, bool initialState, std::string initialVendor, int initialThresholdConcentration, GasType initialGasType = CarbonMonoxide );

        GasType getGasType ( ) const;
        void setGasType ( GasType newGastype );
        int getThresholdConcentration ( ) const;
        void setThresholdConcentration ( int newThresholdConcentration );

        std::string getInformation ( int indentLevel ) const override;
        std::string getOriginString ( ) const override;
        void observeAndReact ( const GeneralSensorObserver * const observer ) const;
};

#endif
