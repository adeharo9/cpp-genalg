#include "Chromosome.h"

#include <limits>
#include <stdexcept>

using namespace genalg;

Chromosome::Chromosome(ulong* genes):
    _genes(genes)
{

}

Chromosome::Chromosome(const Chromosome& chromosome)
{

}

Chromosome::~Chromosome()
{
    delete _genes;
}

void Chromosome::crossover(const Chromosome& chromosome1, const Chromosome& chromosome2, const uint length)
{
    if (length > Chromosome::_chromosome_size ) { throw std::out_of_range(""); }

    uint block = length / Chromosome::_block_size;
    uint bit   = length % Chromosome::_block_size;

    // Full blocks to be copied
    if (block > 0)
    {
        // for?
        // memcopy? -> exists? Yes
        ulong* aux = new ulong[block];
        memcpy((void*)aux, (const void*)chromosome1._genes, block*sizeof(ulong));
        memcpy((void*)chromosome1._genes, (const void*) chromosome2._genes, block*sizeof (ulong));
        memcpy((void*)chromosome2._genes, (const void*) aux, block*sizeof(ulong));
        delete[] aux;
    }

    // Partial block to be copied
    if (block < Chromosome::_chromosome_blocks && bit > 0)
    {
        ulong aux = chromosome1._genes[block];  // copy for swap aid
        ulong mask = ~(0xFFFFFFFFFFFFFFFF << (bit - 1));  // bit is the limit; not to be swapped

        chromosome1._genes[block] = (chromosome1._genes[block] & ~mask) | (chromosome2._genes[block] & mask);
        chromosome2._genes[block] = (chromosome2._genes[block] & ~mask) | (aux & mask);
    }
}

void Chromosome::mutation(const Chromosome& chromosome, const uint point)
{
    if (point >= Chromosome::_chromosome_size ) { throw std::out_of_range(""); }

    uint block = point / Chromosome::_block_size;
    uint bit   = point % Chromosome::_block_size;

    ulong mask = 0b1 << bit;
    chromosome._genes[block] = chromosome._genes[block] ^ mask; // XOR acts inverting the bits with 1s on the mask
}
