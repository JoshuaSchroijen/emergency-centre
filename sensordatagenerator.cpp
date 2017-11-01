#include "sensordatagenerator.h"

void SensorDataGenerator::subscribeSensor ( std::shared_ptr < Sensor > newSensor ) {
    subscribedSensors.push_back ( newSensor );
}

void SensorDataGenerator::unsubscribeSensor ( std::shared_ptr < Sensor > sensorToRemove ) {
    subscribedSensors.remove ( sensorToRemove );
}

