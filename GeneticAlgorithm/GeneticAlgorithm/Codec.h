#pragma once
#include <vector>
#include <memory>
#include "Chromosome.h"


class Codec
{
public:
	Codec(const std::vector<double>& pResolution, const std::vector<std::pair<double, double>>& pRange);
	std::shared_ptr<Chromosome> encode(const std::vector<double>& pValues) const;
	std::shared_ptr<std::vector<double>> decode(const std::shared_ptr<Chromosome>& pBinVal) const;
	std::shared_ptr<Chromosome> getRandomChromosome() const;
private:
	struct Data
	{
		double resolution;
		std::pair<double, double> range;
		int numOfBits;
	};

	std::vector<Data> data_;
};