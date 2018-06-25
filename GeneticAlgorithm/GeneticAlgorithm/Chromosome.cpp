#include "Chromosome.h"

Chromosome::Chromosome()
= default;

Chromosome::~Chromosome()
= default;

Chromosome::Chromosome(const Chromosome& pOther): fitness_(pOther.fitness_)
{
	this->genes_ = std::make_shared<std::vector<bool>>(*pOther.genes_);
}

Chromosome::Chromosome(Chromosome&& pOther) noexcept: genes_(std::move(pOther.genes_)),
                                                      fitness_(pOther.fitness_)
{
}

Chromosome& Chromosome::operator=(const Chromosome& pOther)
{
	if (this == &pOther)
		return *this;
	genes_ = std::make_shared<std::vector<bool>>(*pOther.genes_);
	fitness_ = pOther.fitness_;
	return *this;
}

Chromosome& Chromosome::operator=(Chromosome&& pOther) noexcept
{
	if (this == &pOther)
		return *this;
	genes_ = std::move(pOther.genes_);
	fitness_ = pOther.fitness_;
	return *this;
}

void Chromosome::setGenes(const std::shared_ptr<std::vector<bool>>& pGenes)
{
	genes_ = pGenes;
}

std::shared_ptr<std::vector<bool>> Chromosome::getGenes() const
{
	return genes_;
}

std::ostream& operator<<(std::ostream& pOs, const Chromosome& pObj)
{
	pOs << "genes_: ";
	for (const auto gene : *pObj.genes_)
	{
		pOs << gene;
	}
	return pOs << " fitness_: " << pObj.fitness_;
}
