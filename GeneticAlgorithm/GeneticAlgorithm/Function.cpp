#include "Function.h"



Function::Function()
{
}


Function::~Function()
{
}

double StaticFunction::operator()(const std::vector<double>& pVec) const
{
	double result = 1;
	for (auto it : pVec)
	{
		result *= it;
	}
	return result;
}

