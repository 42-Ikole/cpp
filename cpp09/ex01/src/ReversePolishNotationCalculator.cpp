
#include "ReversePolishNotationCalculator.hpp"

#include <stdexcept>

Equation::Equation(Operator op_, std::optional<int32_t> leftValue_, int32_t rightValue_)
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

int32_t CalculateReversePolishNotation(std::queue<Equation> equationQueue)
{
	if (equationQueue.empty())
	{
		throw std::runtime_error("cannot do calculation with no equation :)");
	}

	int32_t result = 0;
	while (!equationQueue.empty())
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

std::queue<Equation> CreateEquationQueue(const std::string& input)
{
	std::queue<Equation> equationQueue;

	bool shouldBeWhiteScpace = true;
	std::optional<int32_t> firstValue;
	std::optional<int32_t> secondValue;
	for (const auto& c : input)
	{
		shouldBeWhiteScpace = !shouldBeWhiteScpace;
		if (shouldBeWhiteScpace)
		{
			if (!std::isspace(c))
			{
				throw std::runtime_error(
					"Invalid input: `" + input +
					"` numbers used in the calculation need to adhere to 0 <= n < 10. "
					"The allowed operators are be `+`, `-`, `/` and `*`. Note that you "
					"can only use one space in between each digit/operator"
				);
			}
			continue;
		}

		if (!firstValue.has_value())
		{
			if (!std::isdigit(c))
			{
				throw std::runtime_error("Expected a digit but received: " + std::to_string(+c));
			}
			firstValue = c - '0';
			continue;
		}

		if (std::isdigit(c))
		{
			if (secondValue.has_value())
			{
				throw std::runtime_error("Received more than 2 digits in a row");
			}
			secondValue = c - '0';
			continue;
		}

		const auto op = static_cast<Equation::Operator>(c);
		
		if (secondValue.has_value())
		{
			equationQueue.emplace(op, firstValue.value(), secondValue.value());
		}
		else
		{
			equationQueue.emplace(op, std::nullopt, firstValue.value());
		}
		firstValue.reset();
		secondValue.reset();
	}

	if (firstValue.has_value())
	{
		throw std::runtime_error("Invalid equation, equation cannot end with a digit");
	}

	return equationQueue;
}
