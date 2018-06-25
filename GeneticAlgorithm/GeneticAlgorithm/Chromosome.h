#pragma once
#include <vector>
#include <memory>
#include <ostream>

class Chromosome
{
public:
	Chromosome();
	virtual ~Chromosome();
	Chromosome(const Chromosome& pOther);
	Chromosome(Chromosome&& pOther) noexcept;
	Chromosome& operator=(const Chromosome& pOther);
	Chromosome& operator=(Chromosome&& pOther) noexcept;

	void setGenes(const std::shared_ptr<std::vector<bool>>& pGenes);
	std::shared_ptr<std::vector<bool>> getGenes() const;
	void setFitness(const double pFitness){ fitness_ = pFitness; }
	double getFitness() const {return fitness_; }

	friend std::ostream& operator<<(std::ostream& pOs, const Chromosome& pObj);

private:
	std::shared_ptr<std::vector<bool>> genes_{nullptr};
	double fitness_{0};
};