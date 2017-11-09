#ifndef TOXICSENSOR_H
#define TOXICSENSOR_H

#include <string>

class GeneralSensorObserver;

#include "sensor.h"

enum GasType { CarbonMonoxide };

class ToxicGasSensor : public Sensor {
    private:
        GasType sensorGasType;

    public:
        ToxicGasSensor ( ) : Sensor ( ), sensorGasType ( CarbonMonoxide ) { }
        ToxicGasSensor ( std::string initialName, int initialSensorID, bool initialState, std::string initialVendor, GasType initialGasType = CarbonMonoxide );

        GasType getGasType ( ) const;
        void setGasType ( GasType newGastype );

        std::string getInformation ( int indentLevel ) const override;
        void observeAndReact ( const GeneralSensorObserver & observer  );
};

#endif
