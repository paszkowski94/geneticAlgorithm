#include "Selection.h"
#include <algorithm>
#include <functional>



Selection::Selection()
{
}

Selection::~Selection()
= default;

void RouletteSelection::setPopulation(const std::vector<std::shared_ptr<Chromosome>>* pPopulation)
{
	population_ = pPopulation;
	const auto max = findMax();

	rouletteRange_ = 0;

	for(const auto& chromosome: *population_)
	{
		auto localFitness = exp(chromosome->getFitness() / max);
		fitnesses_.push_back(localFitness);
		rouletteRange_ += localFitness;
	}
	//updateRouletteRange();

}

std::shared_ptr<Chromosome> RouletteSelection::selectChromosome() const
{
	const auto rand = [](double pRange)
	{
		return static_cast<double>(std::rand()) / RAND_MAX * pRange;
	};

	auto range = rand(rouletteRange_);

	auto i = 0;
	while (range > 0)
		range -= fitnesses_[i++];

	return population_->at(i-1);
}

double RouletteSelection::findMax() const
{
	auto max = population_->at(0)->getFitness();
	for (const auto& chromosome : *population_)
	{
		if (chromosome->getFitness() > max) max = chromosome->getFitness();
	}
	return max;
}

void RouletteSelection::updateRouletteRange()
{

}

