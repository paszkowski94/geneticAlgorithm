#include "GeneticAlgorithm.h"
#include <iostream>

using namespace std;

GeneticAlgorithm::GeneticAlgorithm() :
	codec_(new Codec({ pow(2, -10) }, { {-4, 4.0} })), function_(new StaticFunction()), selection_(new RouletteSelection()), crossover_(new OnePointCrossover()), mutation_(new BitFlipMutation())
{

}

GeneticAlgorithm::~GeneticAlgorithm()
= default;

void GeneticAlgorithm::prepareRandomPopulation(const size_t pSize)
{
	for (size_t i = 0; i < pSize; i++)
		population_.emplace_back(codec_->getRandomChromosome());
}

void GeneticAlgorithm::fitness()
{
	for(auto& chromosome: population_)
	{
		chromosome->setFitness(function_->operator()(*codec_->decode(chromosome)));
	}
}

void GeneticAlgorithm::writePopulation()
{
	for (const auto& chromosome : population_)
		cout << *chromosome << std::endl;
	cout << endl;
}
