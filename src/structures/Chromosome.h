#pragma once

namespace genalg
{
    class Chromosome
    {
        private:

            using  uint = unsigned int;
            using ulong = unsigned long;

        public:

             Chromosome(ulong* genes);
             Chromosome(const Chromosome& chromosome);
            ~Chromosome();
        
            static void crossover(const Chromosome& chromosome1, const Chromosome& chromosome2, const uint length);
            static void mutation(const Chromosome& chromosome, const uint point);

        private:

            ulong* _genes;

            static uint  _chromosome_size;
            static uint  _chromosome_blocks;
            static const uint _block_size = sizeof(ulong);

    };
}
