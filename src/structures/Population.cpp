#include "Population.h"
#include "../../include/parameters.h"
#include <algorithm>

using namespace genalg;
using namespace std;

Population::Population()
{
    _population = vector<Individual>(POPULATION_SIZE);
}

Population::Population(const Population& population)
{
    _population = population._population;
}

Population::~Population()
{

}

void Population::initialize() {
    PROBLEM_SPECIFICS->initialization(_population);
}

void Population::exterminate() {
    _population.clear();
}

void Population::add(const Individual &individual) {
    _population.emplace_back(individual);
}

void Population::sort() {
    std::sort(_population.begin(), _population.end(), Individual::compareDesc);
}
