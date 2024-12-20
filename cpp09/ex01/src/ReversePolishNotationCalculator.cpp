
#include "ReversePolishNotationCalculator.hpp"

#include <stdexcept>

int32_t AsciiToIntegral(char c)
{
	if (c < '0' || c > '9')
	{
		throw std::runtime_error(std::string("Unable to convert char: ") + c + " to an integral");
	}
	return c - '0';
}

int32_t CalculateReversePolishNotation(std::deque<char> equationStack)
{
	int32_t result = 0;
	while (equationStack.size() >= 3)
	{
		const auto lhs = AsciiToIntegral(PopFirstValueFromDeque(equationStack));
		const auto rhs = AsciiToIntegral(PopFirstValueFromDeque(equationStack));
		const auto op = PopFirstValueFromDeque(equationStack);

		switch (op)
		{
			case '+':
				result = (lhs + rhs);
				break;
			case '-':
				result = (lhs - rhs);
				break;
			case '/':
				result = (lhs / rhs);
				break;
			case '*':
				result = (lhs * rhs);
				break;
			default:
				throw std::runtime_error(std::string("Unknown operator: ") + op);
		}
		equationStack.push_front(result);
	}

	return result;
}
