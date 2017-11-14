#include <iostream>
#include <string>
#include <chrono>
#include <random>

#include "firealarm.h"
#include "policealarm.h"
#include "evacuationalarm.h"

#include "sensorgroup.h"
#include "smokesensor.h"
#include "toxicgassensor.h"
#include "motionsensor.h"

#include <smokesensordatagenerator.h>
#include <toxicgassensordatagenerator.h>
#include <motionsensordatagenerator.h>

#define NUMBER_OF_MODULES 14
#define ROOMS_PER_MODULE  4

int main ( ) {
    std::default_random_engine IDGeneratorEngine;
    std::uniform_int_distribution<int> IDGeneratorDistribution;    
    IDGeneratorEngine.seed ( std::chrono::system_clock::now ( ).time_since_epoch ( ).count ( ) );
    std::default_random_engine vendorGeneratorEngine;
    std::bernoulli_distribution vendorGeneratorDistribution;

    std::shared_ptr < Firealarm > fireAlarm ( new Firealarm ( IDGeneratorDistribution ( IDGeneratorEngine ) ) );
    std::shared_ptr < Policealarm > policeAlarm ( new Policealarm ( IDGeneratorDistribution ( IDGeneratorEngine ) ) );
    std::shared_ptr < Evacuationalarm > evacuationAlarm ( new Evacuationalarm ( IDGeneratorDistribution ( IDGeneratorEngine ) ) );

    std::list < SmokeSensorDataGenerator > smokeSensorDataGenerators;
    std::list < ToxicGasSensorDataGenerator > toxicGasSensorDataGenerators;
    std::list < MotionSensorDataGenerator > motionSensorDataGenerators;

    std::cout << "Welcome to emergency centre!\n";

    SensorGroup GroepT ( "Groep T", IDGeneratorDistribution ( IDGeneratorEngine ), true );

    for ( int module = 1; module <= NUMBER_OF_MODULES; ++module ) {
        SensorGroup * newModule = new SensorGroup ( ( "Module " + std::to_string ( module ) ), IDGeneratorDistribution ( IDGeneratorEngine ), true );
        for ( int room = 1; room <= ROOMS_PER_MODULE; ++room ) {
            std::shared_ptr < SensorGroup > newRoom ( new SensorGroup ( ( "Room " + std::to_string ( room ) ), IDGeneratorDistribution ( IDGeneratorEngine ), true ) );
            std::shared_ptr < SmokeSensor > newSmokeSensor;
            std::shared_ptr < ToxicGasSensor > newToxicGasSensor;
            std::shared_ptr < MotionSensor > newMotionSensor;

            if ( vendorGeneratorDistribution ( vendorGeneratorEngine ) ) {
                newSmokeSensor = std::make_shared < SmokeSensor > ( "Module " + std::to_string ( module ) + ", room " + std::to_string ( room ) + " smoke sensor",
                                                                    IDGeneratorDistribution ( IDGeneratorEngine ),
                                                                    true,
                                                                    "Universal Security Instruments",
                                                                    0.5 );
                newToxicGasSensor = std::make_shared < ToxicGasSensor > ( "Module " + std::to_string ( module ) + ", room " + std::to_string ( room ) + " gas sensor",
                                                                          IDGeneratorDistribution ( IDGeneratorEngine ),
                                                                          true,
                                                                          "Universal Security Instruments",
                                                                          35,
                                                                          CarbonMonoxide );
                newMotionSensor = std::make_shared < MotionSensor > ( "Module " + std::to_string ( module ) + ", room " + std::to_string ( room ) + " motion sensor",
                                                                      IDGeneratorDistribution ( IDGeneratorEngine ),
                                                                      true,
                                                                      "First Alert",
                                                                      0.4,
                                                                      5 );
            } else {
                newSmokeSensor = std::make_shared < SmokeSensor > ( "Module " + std::to_string ( module ) + ", room " + std::to_string ( room ) + " smoke sensor",
                                                                    IDGeneratorDistribution ( IDGeneratorEngine ),
                                                                    true,
                                                                    "First Alert",
                                                                    0.8 );
                newToxicGasSensor = std::make_shared < ToxicGasSensor > ( "Module " + std::to_string ( module ) + ", room " + std::to_string ( room ) + " gas sensor",
                                                                          IDGeneratorDistribution ( IDGeneratorEngine ),
                                                                          true,
                                                                          "First Alert",
                                                                          35,
                                                                          CarbonMonoxide );
                newMotionSensor = std::make_shared < MotionSensor > ( "Module " + std::to_string ( module ) + ", room " + std::to_string ( room ) + " motion sensor",
                                                                      IDGeneratorDistribution ( IDGeneratorEngine ),
                                                                      true,
                                                                      "Philips",
                                                                      0.8,
                                                                      5 );
            }

            SmokeSensorDataGenerator currentRoomSmokeDataGenerator;
            currentRoomSmokeDataGenerator.subscribeSensor ( newSmokeSensor );
            smokeSensorDataGenerators.push_back ( currentRoomSmokeDataGenerator );
            ToxicGasSensorDataGenerator currentRoomToxicGasDataGenerator;
            currentRoomToxicGasDataGenerator.subscribeSensor ( newToxicGasSensor );
            toxicGasSensorDataGenerators.push_back ( currentRoomToxicGasDataGenerator );
            MotionSensorDataGenerator currentRoomMotionDataGenerator;
            currentRoomMotionDataGenerator.subscribeSensor ( newMotionSensor );
            motionSensorDataGenerators.push_back ( currentRoomMotionDataGenerator );

            newSmokeSensor->addAlarm ( fireAlarm );
            newSmokeSensor->addAlarm ( evacuationAlarm );
            newToxicGasSensor->addAlarm ( evacuationAlarm );
            newMotionSensor->addAlarm ( policeAlarm );

            newRoom->addChild ( newSmokeSensor );
            newRoom->addChild ( newToxicGasSensor );
            newRoom->addChild ( newMotionSensor );
            newModule->addChild ( newRoom );
        }

        GroepT.addChild ( newModule );
    }

    std::cout << GroepT.getInformation ( 0 );

    for ( SmokeSensorDataGenerator currentSmokeSensorDataGenerator : smokeSensorDataGenerators ) {
        currentSmokeSensorDataGenerator.generateData ( );
    }
    for ( ToxicGasSensorDataGenerator currentToxicGasSensorDataGenerator : toxicGasSensorDataGenerators ) {
        currentToxicGasSensorDataGenerator.generateData ( );
    }
    for ( MotionSensorDataGenerator currentMotionSensorDataGenerator : motionSensorDataGenerators ) {
        currentMotionSensorDataGenerator.generateData ( );
    }

    return ( 0 );
}
