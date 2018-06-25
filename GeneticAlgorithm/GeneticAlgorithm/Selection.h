#pragma once
#include "Chromosome.h"
#include <algorithm>

class Selection
{
public:
	explicit Selection();
	virtual ~Selection();

	Selection(const Selection& pOther) = delete;
	Selection(Selection&& pOther) noexcept = delete;
	Selection& operator=(const Selection& pOther) = delete;
	Selection& operator=(Selection&& pOther) noexcept = delete;

	virtual void setPopulation(const std::vector<std::shared_ptr<Chromosome>>* pPopulation) { population_ = pPopulation; }
	virtual std::shared_ptr<Chromosome> selectChromosome() const = 0;

protected:
	const std::vector<std::shared_ptr<Chromosome>>* population_;
};

class RouletteSelection: public Selection
{
public:
	RouletteSelection() = default;
	~RouletteSelection() = default;
	RouletteSelection(const RouletteSelection& pOther) = delete;
	RouletteSelection(RouletteSelection&& pOther) noexcept = delete;
	RouletteSelection& operator=(const RouletteSelection& pOther) = delete;
	RouletteSelection& operator=(RouletteSelection&& pOther) noexcept = delete;

	void setPopulation(const std::vector<std::shared_ptr<Chromosome>>* pPopulation) override;
	std::shared_ptr<Chromosome> selectChromosome() const override;

protected:
	double findMax() const;
	void updateRouletteRange();

private:
	double rouletteRange_{};
	std::vector<double> fitnesses_;
};

