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

             double normalizedFitness() const;
             double fitness() const;
             const Chromosome& getChromosome() const;
             void update();
             void normalize(double totalFitness);
             void operator=(const Individual& individual);

             static bool compareDesc(const Individual& first, const Individual& second);

        private:

            Chromosome chromosome;
            double _normalizedFitness;
            double _fitness;
    };
}
