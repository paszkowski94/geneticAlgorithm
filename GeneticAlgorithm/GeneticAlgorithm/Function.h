#pragma once
#include <vector>

class Function
{
public:
	Function();
	virtual ~Function();
	Function(const Function& pOther) = delete;
	Function(Function&& pOther) noexcept = delete;
	Function& operator=(const Function& pOther) = delete;
	Function& operator=(Function&& pOther) noexcept = delete;

	virtual double operator()(const std::vector<double>& pVec) const = 0;
};

class StaticFunction: public Function
{
public:
	double operator()(const std::vector<double>& pVec) const override;
};