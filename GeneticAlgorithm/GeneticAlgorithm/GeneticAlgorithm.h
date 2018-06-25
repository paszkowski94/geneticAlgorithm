#pragma once
#include <vector>
#include <memory>
#include "Chromosome.h"
#include "Codec.h"
#include "Function.h"
#include "Selection.h"
#include "Crossover.h"
#include <iostream>
#include "Mutation.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm();
	virtual ~GeneticAlgorithm();
	GeneticAlgorithm(const GeneticAlgorithm& pOther) = delete;
	GeneticAlgorithm(GeneticAlgorithm&& pOther) noexcept = delete;
	GeneticAlgorithm& operator=(const GeneticAlgorithm& pOther) = delete;
	GeneticAlgorithm& operator=(GeneticAlgorithm&& pOther) noexcept = delete;

	void prepareRandomPopulation(size_t pSize);
	void fitness();
	void writePopulation();

	void run()
	{
		prepareRandomPopulation(20);

		while (1)
		{
			fitness();
			selection_->setPopulation(&population_);
			std::vector<std::shared_ptr<Chromosome>> tmp_population;
			for (size_t i = 0; i < population_.size(); i++)
			{
				const std::shared_ptr<Chromosome> tmp_chromosome1(new Chromosome(*selection_->selectChromosome()));
				const std::shared_ptr<Chromosome> tmp_chromosome2(new Chromosome(*selection_->selectChromosome()));
				crossover_->crossover(tmp_chromosome1, tmp_chromosome2);
				tmp_population.emplace_back(tmp_chromosome1);
			}
			population_ = tmp_population;
			mutation_->mutate(population_);

			writePopulation();
		}
	}

private:
	std::vector<std::shared_ptr<Chromosome>> population_;
	std::unique_ptr<Codec> codec_;
	std::unique_ptr<Function> function_;
	std::unique_ptr<Selection> selection_;
	std::unique_ptr<Crossover> crossover_;
	std::unique_ptr<Mutation> mutation_;
};
