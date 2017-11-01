#include <chrono>

#include "sensorobserver.hpp"
#include "smokesensordatagenerator.h"

SmokeSensorDataGenerator::SmokeSensorDataGenerator ( ) {
    smokeLevelGeneratorEngine.seed ( std::chrono::system_clock::now ( ).time_since_epoch ( ).count ( ) );
}

void SmokeSensorDataGenerator::generateData ( ) {
    SensorObserver<double> smokeObserver;
    for ( std::shared_ptr < Sensor > currentSmokeSensor : subscribedSensors ) {
        smokeObserver.setStoredDataElement ( smokeLevelGeneratorDistribution ( smokeLevelGeneratorEngine ) );
        currentSmokeSensor->observeAndReact ( smokeObserver );
    }
}
