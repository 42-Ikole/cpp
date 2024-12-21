
#include "ReversePolishNotationCalculator.hpp"

#include <iostream>
#include <stdexcept>

Equation::Equation(Operator op_, int32_t leftValue_, int32_t rightValue_)
	: op(op_)
	, leftValue(leftValue_)
	, rightValue(rightValue_)
{
}

void Equation::SetLeftValue(int32_t newValue)
{
	leftValue = newValue;
}

bool Equation::IsLeftValueSet() const
{
	return leftValue.has_value();
}

int32_t Equation::Execute() const
{
	if (!IsLeftValueSet())
	{
		throw std::runtime_error("Cannot execute equation because it is not complete, the left value has not yet been set.");
	}

	switch (op)
	{
		case Operator::plus:
			return leftValue.value() + rightValue;
		case Operator::minus:
			return leftValue.value() - rightValue;
		case Operator::divide:
			return leftValue.value() / rightValue;
		case Operator::multiply:
			return leftValue.value() * rightValue;
		default:
			throw std::runtime_error("Unknown operator: " + std::to_string(static_cast<int32_t>(op)));
	}
}

int32_t CalculateReversePolishNotation(std::queue<Equation> equationQueue);
{
	int32_t result = 0;
	while (equationDeque.size() >= 3)
	{
		auto currentEquation = equationQueue.front();
		equationQueue.pop();
		if (!currentEquation.IsLeftValueSet())
		{
			currentEquation.SetLeftValue(result);
		}
		result = currentEquation.Execute();
	}

	return result;
}

std::queue<Equation> CreateEquationStack(const std::string& input)
{
	std::queue<Equation> equationStack;

	bool shouldBeWhiteScpace = false;
	for (const auto& c : input)
	{
		if (shouldBeWhiteScpace && !std::isspace(c))
		{
			throw std::runtime_error(
				"Invalid input: `" + input +
				"` numbers used in the calculation need to adhere to 0 <= n < 10. "
				"The allowed operators are be `+`, `-`, `/` and `*`"
			);
		}
		
		shouldBeWhiteScpace = !shouldBeWhiteScpace;
	}

	return equationStack;
}
