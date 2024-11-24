
//--------------------------------------------------

#include <random>

#include "RNG.h"

//--------------------------------------------------

namespace RandomNumberGenerator {

    double generate_between (double min, double max) {

        std::random_device rd;
        std::mt19937 generator(rd ());
        std::uniform_real_distribution<> distribution(min, max);

        return distribution (generator);
    }
};

//--------------------------------------------------
