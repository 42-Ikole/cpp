#pragma once

#include <inttypes.h>
#include <queue>
#include <optional>
#include <string>

class Equation
{
public:

	/*!
	 * @brief
	*/
	enum class Operator
	{
		plus = '+',
		minus = '-',
		divide = '/',
		multiply = '*'
	};

private:	

	const Operator op; /*!< -. */
	std::optional<int32_t> leftValue; /*!< -.*/
	const int32_t rightValue; /*!< -. */

public:

	Equation(Operator op_, std::optional<int32_t> leftValue_, int32_t rightValue_);

	bool IsLeftValueSet() const;

	void SetLeftValue(int32_t newValue);

	int32_t Execute() const;

};

int32_t CalculateReversePolishNotation(std::queue<Equation> equationQueue);

std::queue<Equation> CreateEquationStack(const std::string& input);
