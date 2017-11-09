#include <iostream>
#include <string>
#include <chrono>
#include <random>

#include "sensorgroup.h"
#include "smokesensor.h"
#include "toxicgassensor.h"
#include "motionsensor.h"

#define NUMBER_OF_MODULES 14
#define ROOMS_PER_MODULE  4

int main() {
    std::default_random_engine IDGeneratorEngine;
    std::uniform_int_distribution<int> IDGeneratorDistribution;    
    IDGeneratorEngine.seed ( std::chrono::system_clock::now ( ).time_since_epoch ( ).count ( ) );
    std::default_random_engine vendorGeneratorEngine;
    std::bernoulli_distribution vendorGeneratorDistribution;

    std::cout << "Welcome to emergency centre!\n";

    SensorGroup GroepT ( "Groep T", IDGeneratorDistribution ( IDGeneratorEngine ), true );

    for ( int module = 1; module <= NUMBER_OF_MODULES; ++module ) {
        SensorGroup * newModule = new SensorGroup ( ( "Module " + std::to_string ( module ) ), IDGeneratorDistribution ( IDGeneratorEngine ), true );
        for ( int room = 1; room <= ROOMS_PER_MODULE; ++room ) {
            SensorGroup * newRoom = new SensorGroup ( ( "Room " + std::to_string ( room ) ), IDGeneratorDistribution ( IDGeneratorEngine ), true );
            SmokeSensor * newSmokeSensor;
            ToxicGasSensor * newToxicGasSensor;
            MotionSensor * newMotionSensor;

            if ( vendorGeneratorDistribution ( vendorGeneratorEngine ) ) {
                newSmokeSensor = new SmokeSensor ( "Module " + std::to_string ( module ) + ", room " + std::to_string ( room ) + " smoke sensor",
                                                   IDGeneratorDistribution ( IDGeneratorEngine ),
                                                   true,
                                                   "Universal Security Instruments",
                                                   0.5 );
                newToxicGasSensor = new ToxicGasSensor ( "Module " + std::to_string ( module ) + ", room " + std::to_string ( room ) + " gas sensor",
                                                         IDGeneratorDistribution ( IDGeneratorEngine ),
                                                         true,
                                                         "Universal Security Instruments" );
                newMotionSensor = new MotionSensor ( "Module " + std::to_string ( module ) + ", room " + std::to_string ( room ) + " motion sensor",
                                                     IDGeneratorDistribution ( IDGeneratorEngine ),
                                                     true,
                                                     "First Alert",
                                                     0.1,
                                                     5 );
            } else {
                newSmokeSensor = new SmokeSensor ( "Module " + std::to_string ( module ) + ", room " + std::to_string ( room ) + " smoke sensor",
                                                   IDGeneratorDistribution ( IDGeneratorEngine ),
                                                   true,
                                                   "First Alert",
                                                   0.5 );
                newToxicGasSensor = new ToxicGasSensor ( "Module " + std::to_string ( module ) + ", room " + std::to_string ( room ) + " gas sensor",
                                                         IDGeneratorDistribution ( IDGeneratorEngine ),
                                                         true,
                                                         "First Alert" );
                newMotionSensor = new MotionSensor ( "Module " + std::to_string ( module ) + ", room " + std::to_string ( room ) + " motion sensor",
                                                     IDGeneratorDistribution ( IDGeneratorEngine ),
                                                     true,
                                                     "Philips",
                                                     0.1,
                                                     5 );
            }

            newRoom->addChild ( newSmokeSensor );
            newRoom->addChild ( newToxicGasSensor );
            newRoom->addChild ( newMotionSensor );
            newModule->addChild ( newRoom );
        }

        GroepT.addChild ( newModule );
    }

    std::cout << GroepT.getInformation ( 0 );

    return ( 0 );
}
