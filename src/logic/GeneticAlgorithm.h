#pragma once

#include "../structures/Population.h"
#include <vector>

namespace genalg
{
    class GeneticAlgorithm
    {
        public:

             GeneticAlgorithm();
             GeneticAlgorithm(const GeneticAlgorithm& geneticAlgorithm);
            ~GeneticAlgorithm();

            void run();

        private:

            Population population;
            std::vector<Individual> selected;
            const Individual* bestIndividual;
            double lastFitness;
            int numIterations;

            void initialize();
            void selection();
            bool crossover(const Chromosome &chromosome1, const Chromosome &chromosome2);
            bool mutation(const Chromosome& chromosome);
            void recombineSelected();
            void pickBest();
            void updateControl();
            bool finished();

    };
}
