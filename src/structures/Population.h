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
             const std::vector<Individual>& individuals() const;
             void exterminate();
             void add(const Individual& individual);
             void normalizeFitness();
             void sort();

        private:

            std::vector<Individual> _population;
    };
}
