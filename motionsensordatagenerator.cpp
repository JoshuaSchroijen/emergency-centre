#include <chrono>

#include "sensorobserver.hpp"
#include "motionsensor.h"
#include "motionsensordatagenerator.h"

MotionSensorDataGenerator::MotionSensorDataGenerator ():
    SensorDataGenerator ( ),
    motionGeneratorDistribution ( 0.01 ) {
    motionGeneratorEngine.seed ( std::chrono::system_clock::now ( ).time_since_epoch ( ).count ( ) );
}

void MotionSensorDataGenerator::generateData ( ) {
    SensorObserver<bool> motionObserver;

    for ( std::shared_ptr < Sensor > currentMotionSensor : subscribedSensors ) {
        motionObserver.setStoredDataElement ( motionGeneratorDistribution ( motionGeneratorEngine ) );
        currentMotionSensor->observeAndReact ( motionObserver );
    }
}
