#pragma once
#include "Chromosome.h"

class Crossover
{
public:
	Crossover();
	virtual ~Crossover();
	Crossover(const Crossover& pOther) = delete;
	Crossover(Crossover&& pOther) noexcept = delete;
	Crossover& operator=(const Crossover& pOther) = delete;
	Crossover& operator=(Crossover&& pOther) noexcept = delete;

	virtual void crossover(std::shared_ptr<Chromosome> pC1, std::shared_ptr<Chromosome> pC2) const = 0;
};

class OnePointCrossover : public Crossover
{
public:
	OnePointCrossover() = default;
	virtual ~OnePointCrossover() = default;
	OnePointCrossover(const OnePointCrossover& pOther) = delete;
	OnePointCrossover(OnePointCrossover&& pOther) noexcept = delete;
	OnePointCrossover& operator=(const OnePointCrossover& pOther) = delete;
	OnePointCrossover& operator=(OnePointCrossover&& pOther) noexcept = delete;

	void crossover(std::shared_ptr<Chromosome> pC1, std::shared_ptr<Chromosome> pC2) const override;
};


