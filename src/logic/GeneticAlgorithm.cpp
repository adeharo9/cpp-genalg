#include "GeneticAlgorithm.h"

using namespace genalg;

GeneticAlgorithm::GeneticAlgorithm()
{

}

GeneticAlgorithm::GeneticAlgorithm(const GeneticAlgorithm& geneticAlgorithm)
{

}

GeneticAlgorithm::~GeneticAlgorithm()
{
    
}

void GeneticAlgorithm::run() {
    initialize();
    pickBest();

    while (!finished())
    {
        selection();
        recombineSelected();
        pickBest();
        updateControl();
    }
}

void GeneticAlgorithm::initialize() {
    bestIndividual = nullptr;
    population.initialize();
}

void GeneticAlgorithm::selection() {
    // Here population is already sorted since it gets sorted on pickBest() function
    // of last iteration
    for (int i = 0; i < population.individuals().size(); ++i) {
        double cumulativeFitness = 0;
        //TODO: Maybe we want a random engine or this is fine?
        double r = (rand()%1000) / 10000.;

        for (Individual individual: population.individuals())
        {
            cumulativeFitness += individual.normalizedFitness();

            if (cumulativeFitness >= r)
            {
                selected.emplace_back(Individual(individual));
                break;
            }
        }
    }

    population.exterminate();
}

bool GeneticAlgorithm::crossover(const Chromosome& chromosome1, const Chromosome& chromosome2) {
    //TODO: Crossover probability
    if ((rand()%1000) / 10000. > 0.5)
        return false;

    int crossoverLength = rand()%Chromosome::_chromosome_size;
    Chromosome::crossover(chromosome1, chromosome2, crossoverLength);
    //TODO: Do we want to backtrack if the crossover does not generate solutions?

    return true;
}

bool GeneticAlgorithm::mutation(const Chromosome &chromosome) {
    // Only mutate some of the times
    //TODO: Mutation probability
    if ((rand()%1000) / 10000. > 0.05)
        return false;

    int mutationPoint = rand()%Chromosome::_chromosome_size;
    Chromosome::mutation(chromosome, mutationPoint);
    //TODO: Do we want to backtrack if the mutation does not generate solutions?

    return true;
}

void GeneticAlgorithm::recombineSelected() {
    int i1, i2;
    bool modified1, modified2;

    while (selected.size() >= 2) // While there are still pairs
    {
        // Select a random pair among those remaining selected
        i1 = rand()%selected.size();
        i2 = rand()%selected.size();

        // Ensure no chromosome is recombined with itself
        // always ensuring random choice
        while (i1 == i2)
        {
            i2 = rand()%selected.size();
        }

        Chromosome chromosome1 = selected[i1].getChromosome();
        Chromosome chromosome2 = selected[i2].getChromosome();

        modified1 = modified2 = crossover(chromosome1, chromosome2);
        modified1 |= mutation(chromosome1);
        modified2 |= mutation(chromosome2);

        if (modified1)
        {
            selected[i1].update();
        }

        if (modified2)
        {
            selected[i2].update();
        }


        population.add(selected[i1]);
        population.add(selected[i2]);
        selected.erase(selected.begin() + i1);
        selected.erase(selected.begin() + (i1 < i2 ? i2-1 : i2));
    }

    // Here selected.size() can be 0 or 1

    // Input case there is still an element, do not do crossover
    // on it but allow it to mutate
    if (!selected.empty())    // If there is 1 element
    {
        modified1 = mutation(selected[0].getChromosome());

        if (modified1)
        {
            selected[0].update();
        }

        population.add(selected[0]);
        selected.erase(selected.begin());
    }
}

void GeneticAlgorithm::pickBest() {
    population.normalizeFitness();
    //TODO: sort in desc normalized fitness order

    if (bestIndividual != nullptr)
    {
        lastFitness = bestIndividual->fitness();
    }
    bestIndividual = &population.individuals()[0];
}

void GeneticAlgorithm::updateControl() {
    ++numIterations;
}

bool GeneticAlgorithm::finished() {
    //FIXME: In the first iteration, lastFitness is undefined
    double tolerance = abs(bestIndividual->fitness() - lastFitness) / lastFitness;
    //FIXME: Finalization parameters
    return numIterations >= 1 || tolerance <= 9999;
}
