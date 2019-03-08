#ifndef TASKINTERFACE_H
#define TASKINTERFACE_H

#include "../src/structures/Chromosome.h"
#include "../src/structures/Individual.h"
#include <vector>

namespace genalg {
    class TaskInterface {
    public:
        virtual double fitness(const genalg::Chromosome& chromosome) = 0;
        virtual void initialization(std::vector<Individual>& population) = 0;

        virtual ~TaskInterface();
    };
}

#endif // TASKINTERFACE_H
