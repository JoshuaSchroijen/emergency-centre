#include <chrono>

#include "sensorobserver.hpp"
#include "toxicgassensor.h"
#include "toxicgassensordatagenerator.h"

ToxicGasSensorDataGenerator::ToxicGasSensorDataGenerator ( ) :
    SensorDataGenerator ( ),
    gasConcentrationGeneratorDistribution ( 0, 13000 ) {
    gasConcentrationGeneratorEngine.seed ( std::chrono::system_clock::now ( ).time_since_epoch ( ).count ( ) );
}

void ToxicGasSensorDataGenerator::generateData ( ) {
    SensorObserver<int> toxicGasObserver;
    for ( std::shared_ptr < Sensor > currentToxicGasSensor : subscribedSensors ) {
        toxicGasObserver.setStoredDataElement ( gasConcentrationGeneratorDistribution ( gasConcentrationGeneratorEngine ) );
        currentToxicGasSensor->observeAndReact ( toxicGasObserver );
    }
}
