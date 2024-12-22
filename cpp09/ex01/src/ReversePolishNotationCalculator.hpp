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

	Equation& operator = (const Equation& rhs) = delete;

public:

	/*!
	 * @brief
	 * @param op_
	 * @param leftValue_ (leave empty if you want to set it later, i.e. needs result of other equation)
	 * @param rightValue_
	*/
	Equation(Operator op_, std::optional<int32_t> leftValue_, int32_t rightValue_);

	/*!
	 * @brief
	 * @param rhs
	*/
	Equation(const Equation& rhs) = default;


	/*!
	 * @brief
	 * @return
	*/
	bool IsLeftValueSet() const;

	/*!
	 * @brief
	 * @param newValue
	*/
	void SetLeftValue(int32_t newValue);

	/*!
	 * @brief
	 * @return Result of the equation.
	*/
	int32_t Execute() const;

};

int32_t CalculateReversePolishNotation(std::queue<Equation> equationQueue);

std::queue<Equation> CreateEquationQueue(const std::string& input);
