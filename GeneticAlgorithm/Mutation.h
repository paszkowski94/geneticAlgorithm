#pragma once
#include <memory>
#include <vector>
#include "Chromosome.h"

class Mutation
{
public:
	Mutation();
	virtual ~Mutation();
	Mutation(const Mutation& pOther) = delete;
	Mutation(Mutation&& pOther) noexcept = delete;
	Mutation& operator=(const Mutation& pOther) = delete;
	Mutation& operator=(Mutation&& pOther) noexcept = delete;

	double getMutationProbability() const {	return mutationProbability_; }
	void setMutationProbability(const double pMutationProbability) { mutationProbability_ = pMutationProbability; }

	virtual void mutate(std::vector<std::shared_ptr<Chromosome>> pPopulation) = 0;
	virtual void mutate(Chromosome& pChromosome) = 0;
private:
	double mutationProbability_{};
};


class BitFlipMutation : public Mutation
{
public:
	BitFlipMutation() = default;
	virtual ~BitFlipMutation() = default;
	BitFlipMutation(const BitFlipMutation& pOther) = delete;
	BitFlipMutation(BitFlipMutation&& pOther) noexcept = delete;
	BitFlipMutation& operator=(const BitFlipMutation& pOther) = delete;
	BitFlipMutation& operator=(BitFlipMutation&& pOther) noexcept = delete;

	void mutate(std::vector<std::shared_ptr<Chromosome>> pPopulation) override
	{
		auto rand = []()
		{
			return static_cast<double>(std::rand()) / RAND_MAX;
		};

		for(auto& chromosome: pPopulation)
		{
			const auto genes = chromosome->getGenes();

			for (auto&& i : *genes)
			{
				i = !i;
			}
		}
	}


	virtual void mutate(Chromosome& pChromosome) override
	{
		
	}
};
