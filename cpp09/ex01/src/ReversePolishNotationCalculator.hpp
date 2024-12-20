#pragma once

#include <inttypes.h>
#include <deque>

template<class T>
T PopFirstValueFromDeque(std::deque<T>& deque)
{
	T value = deque.front();
	deque.pop_front();
	return value;
}

int32_t AsciiToIntegral(char c);

int32_t CalculateReversePolishNotation(std::deque<char> equationDeque);
