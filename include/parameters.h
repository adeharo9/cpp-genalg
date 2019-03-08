#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>
#include "taskinterface.h"

namespace genalg
{
// Initial state parameters
static const int POPULATION_SIZE = 500;
static const unsigned int CHROMOSOME_TYPE_SIZE = 64;

// Inner working parameters
static const double CROSSOVER_PROBABILITY = 0.5;
static const double MUTATION_PROBABILITY = 0.05;
static const unsigned int MAX_RETRIES_CROSSOVER = 1000;
static const unsigned int MAX_RETRIES_MUTATION = 1000;

// Finish condition parameters
static const unsigned int MAX_NUM_ITERATIONS = 5000;
static const double END_TOLERANCE = 0.001;
// static const double END_THRESHOLD = 1;

// Input files source folder
static const std::string CHALLENGE_NAME = "pizza";
static const std::string INPUT_DIRECTORY = "./input";
static const std::string OUTPUT_DIRECTORY = "./output";

static std::string INPUT_FILES_DIR;
static std::string OUTPUT_FILES_DIR;
static size_t CHROMOSOME_BLOCKS;
static size_t CHROMOSOME_SIZE;

static genalg::TaskInterface* PROBLEM_SPECIFICS;

void Init();
std::string inputFilesDir();

}

#endif // PARAMETERS_H
