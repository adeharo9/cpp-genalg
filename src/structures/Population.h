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

        private:

            std::vector<Individual> _population;
    }
}
