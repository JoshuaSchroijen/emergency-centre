#include <chrono>

#include "sensorobserver.hpp"
#include "smokesensordatagenerator.h"

SmokeSensorDataGenerator::SmokeSensorDataGenerator ( ) {
    smokeLevelGeneratorEngine.seed ( std::chrono::system_clock::now ( ).time_since_epoch ( ).count ( ) );
}

void SmokeSensorDataGenerator::generateData ( ) {
    std::shared_ptr < SensorObserver < double > > smokeObserver = std::make_shared < SensorObserver < double > > ( );
    for ( std::shared_ptr < Sensor > currentSmokeSensor : subscribedSensors ) {
        smokeObserver->setStoredDataElement ( smokeLevelGeneratorDistribution ( smokeLevelGeneratorEngine ) );
        currentSmokeSensor->observeAndReact ( smokeObserver.get ( ) );
    }
}
