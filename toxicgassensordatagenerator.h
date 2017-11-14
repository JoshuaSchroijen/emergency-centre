#ifndef TOXICGASSENSORDATAGENERATOR_H
#define TOXICGASSENSORDATAGENERATOR_H

#include <list>
#include <memory>
#include <random>

class ToxicGasSensor;

#include "sensordatagenerator.h"

class ToxicGasSensorDataGenerator : public SensorDataGenerator {
    private:
        std::list < std::shared_ptr < ToxicGasSensor > > subscribedToxicGasSensors;

        std::default_random_engine gasConcentrationGeneratorEngine;
        std::uniform_int_distribution<int> gasConcentrationGeneratorDistribution;

    public:
        ToxicGasSensorDataGenerator ( );

        void subscribeToxicGasSensor ( std::shared_ptr < ToxicGasSensor > newToxicGasSensor );
        void unsubscribeToxicGasSensor ( std::shared_ptr < ToxicGasSensor > toxicGasSensorToRemove );

        void generateData ( ) override;
};

#endif
