#include "Crossover.h"



Crossover::Crossover()
{
}


Crossover::~Crossover()
{
}

void OnePointCrossover::crossover(std::shared_ptr<Chromosome> pC1, std::shared_ptr<Chromosome> pC2) const
{
	auto pc1 = pC1->getGenes();
	auto pc2 = pC2->getGenes();

	auto c1 = *pC1->getGenes();
	auto c2 = *pC2->getGenes();

	const auto cross_point = std::rand() % c1.size();

	for (size_t i = 0; i < cross_point; i++)
	{
		pC1->getGenes()->at(i) = c2[i];
		pC2->getGenes()->at(i) = c1[i];
	}
}
