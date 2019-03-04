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

        private:

            Chromosome chromosome;
    };
}
