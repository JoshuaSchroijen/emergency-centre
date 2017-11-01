#ifndef MOTIONSENSORDATAGENERATOR_H
#define MOTIONSENSORDATAGENERATOR_H

#include <list>
#include <memory>
#include <random>

#include "sensordatagenerator.h"

class MotionSensorDataGenerator : public SensorDataGenerator {
    private:
        std::default_random_engine motionGeneratorEngine;
        std::bernoulli_distribution motionGeneratorDistribution;

    public:
        MotionSensorDataGenerator ( );

        void generateData ( );
};

#endif
