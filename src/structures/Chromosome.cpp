#include "Chromosome.h"
#include "../../include/parameters.h"

#include <limits>
#include <stdexcept>

using namespace genalg;

Chromosome::Chromosome() {
    _genes = new ulong[CHROMOSOME_BLOCKS];
}

Chromosome::Chromosome(ulong* genes):
    _genes(genes)
{

}

Chromosome::Chromosome(const Chromosome& chromosome)
{
    _genes = new ulong[CHROMOSOME_BLOCKS];
    memcpy((void*)_genes, (const void*)chromosome._genes, CHROMOSOME_BLOCKS*sizeof(ulong));
}

Chromosome::~Chromosome()
{
    delete[] _genes;
}

void Chromosome::operator=(const Chromosome &chromosome) {
    memcpy((void*)_genes, (const void*)chromosome._genes, CHROMOSOME_BLOCKS*sizeof(ulong));
}

void Chromosome::crossover(const Chromosome& chromosome1, const Chromosome& chromosome2, const uint length)
{
    if (length > CHROMOSOME_SIZE ) { throw std::out_of_range(""); }

    uint block = length / CHROMOSOME_BLOCKS;
    uint bit   = length % CHROMOSOME_BLOCKS;

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
    if (block < CHROMOSOME_BLOCKS && bit > 0)
    {
        ulong aux = chromosome1._genes[block];  // copy for swap aid
        ulong mask = ~(0xFFFFFFFFFFFFFFFF << (bit - 1));  // bit is the limit; not to be swapped

        chromosome1._genes[block] = (chromosome1._genes[block] & ~mask) | (chromosome2._genes[block] & mask);
        chromosome2._genes[block] = (chromosome2._genes[block] & ~mask) | (aux & mask);
    }
}

void Chromosome::mutation(const Chromosome& chromosome, const uint point)
{
    if (point >= CHROMOSOME_SIZE ) { throw std::out_of_range(""); }

    uint block = point / Chromosome::_block_size;
    uint bit   = point % Chromosome::_block_size;

    ulong mask = 0b1 << bit;
    chromosome._genes[block] = chromosome._genes[block] ^ mask; // XOR acts inverting the bits with 1s on the mask
}
