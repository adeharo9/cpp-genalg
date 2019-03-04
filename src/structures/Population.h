#pragma once

#include "Individual.h"

#include <vector>

namespace genalg
{
    class Population
    {
        public:

             Population();
             Population(const Population& population);
            ~Population();

             void initialize();
             std::vector<Individual>& individuals();
             void exterminate();
             void add(const Individual& individual);
             void normalizeFitness();

        private:

            std::vector<Individual> _population;
    };
}
