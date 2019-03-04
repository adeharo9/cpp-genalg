#pragma once

#include "Chromosome.h"

namespace genalg
{
    class Individual
    {
        public:

             Individual();
             Individual(const Individual& individual);
            ~Individual();

             double normalizedFitness();
             double fitness();
             const Chromosome& getChromosome();
             void update();

        private:

            Chromosome chromosome;
    };
}
