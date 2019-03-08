#include "Individual.h"
#include "../../include/parameters.h"

using namespace genalg;

Individual::Individual()
{
    _fitness = _normalizedFitness = -1;
}

Individual::Individual(const Individual& individual)
{
    chromosome = individual.chromosome;
    _normalizedFitness = individual._normalizedFitness;
    _fitness = individual._fitness;
}

Individual::~Individual()
{
    
}

double Individual::fitness() const {
    return _fitness;
}

double Individual::normalizedFitness() const {
    return _normalizedFitness;
}

void Individual::normalize(double totalFitness) {
    _normalizedFitness = _fitness/totalFitness;
}

void Individual::update() {
    _fitness = PROBLEM_SPECIFICS->fitness(chromosome);
}

void Individual::operator=(const Individual &individual) {
    _fitness = individual._fitness;
    _normalizedFitness = individual._normalizedFitness;
    chromosome = individual.chromosome;
}

bool Individual::compareDesc(const Individual& first, const Individual& second) {
    return first.fitness() > second.fitness();
}
