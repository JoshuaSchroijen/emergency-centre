#ifndef SMOKESENSORDATAGENERATOR_H
#define SMOKESENSORDATAGENERATOR_H

#include <random>

#include "sensordatagenerator.h"

class SmokeSensorDataGenerator : public SensorDataGenerator {
    private:
        std::default_random_engine smokeLevelGeneratorEngine;
        std::uniform_real_distribution<double> smokeLevelGeneratorDistribution;

    public:
        SmokeSensorDataGenerator ( );

        void generateData ( );
};

#endif
