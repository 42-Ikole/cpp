#pragma once

#include <type_traits>

template <std::is_integral T>
class SortedPair
{
private:

	T smallerValue; /*!< -. */
	T biggerValue; /*!< -. */

	/*!
	 * @brief
	*/
	SortedPair() = delete;

public:

	/*!
	 * @brief Stores first and second in smaller/bigger accordingly based on their value.
	 * @param first
	 * @param second
	*/
	SortedPair(T first, T second)
	{
		if (first < second)
		{
			smallerValue = first;
			biggerValue = second;
		}
		else
		{
			smallerValue = second;
			biggerValue = first;
		}
	}

	/*!
	 * @brief
	*/
	~SortedPair() = default;

	/*!
	 * @brief
	 * @param rhs
	 * @return
	*/
	SortedPair& opreator = (const SortedPair& rhs) = default;

	/*!
	 * @brief
	 * @return
	*/
	T SmallerValue() const
	{
		return smallerValue;
	}

	/*!
	 * @brief
	 * @return
	*/
	T BiggerValue() const
	{
		return biggerValue;
	}
};
