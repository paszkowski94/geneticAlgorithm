#include "Codec.h"
#include <ctime>

Codec::Codec(const std::vector<double>& pResolution, const std::vector<std::pair<double, double>>& pRange)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::vector<bool> result;
	auto result_ptr = std::make_shared<std::vector<bool>>(result);
	auto resolution = pResolution.begin();
	auto range = pRange.begin();

	while (resolution != pResolution.end())
	{
		data_.push_back(Data{ *resolution, *range, 0 });
		++resolution;
		++range;
	}

	for (auto& it : data_)
	{
		const auto length = it.range.second - it.range.first;
		const auto num_of_combinations = length / it.resolution;
		it.numOfBits = static_cast<int>(ceil(log2(num_of_combinations)));
	}
}

std::shared_ptr<Chromosome> Codec::encode(const std::vector<double>& pValues) const
{
	std::vector<bool> result;

	auto data = data_.begin();
	auto val = pValues.begin();

	while (val != pValues.end())
	{
		const auto temp = *val - data->range.first;
		auto binary_val = static_cast<long long>(temp / data->resolution);

		std::vector<bool> bits;

		for (auto i = 0; i < data->numOfBits; i++)
		{
			bits.push_back(binary_val % 2);
			binary_val /= 2;
		}

		for (auto it = bits.rbegin(); it != bits.rend(); ++it)
		{
			result.push_back(*it);
		}

		++data;
		++val;
	}

	Chromosome chromosome;
	chromosome.setGenes(std::make_shared<std::vector<bool>>(result));
	return std::make_shared<Chromosome>(chromosome);
}

std::shared_ptr<std::vector<double>> Codec::decode(const std::shared_ptr<Chromosome>& pBinVal) const
{
	std::vector<double> result;
	auto result_ptr = std::make_shared<std::vector<double>>(result);
	auto shift = 0;

	for (auto& it : data_)
	{
		long long val = 0;
		for (auto i = 0; i < it.numOfBits; i++)
		{
			val = 2 * val + pBinVal->getGenes()->at(i + shift);
		}
		shift += it.numOfBits;
		result_ptr->push_back(val * it.resolution);
	}

	return result_ptr;
}

std::shared_ptr<Chromosome> Codec::getRandomChromosome() const
{
	Chromosome chromosome;
	auto genes = std::make_shared<std::vector<bool>>(std::vector<bool>());
	
	for(auto it: data_)
		for(auto i = 0; i < it.numOfBits; i++)
			genes->push_back(rand() % 2);

	chromosome.setGenes(genes);

	return std::make_shared<Chromosome>(chromosome);
}

