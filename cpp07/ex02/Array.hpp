
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template<typename T>
class Array
{
	private:
		T				*m_array;
		unsigned int	m_size;
	public:
		Array() :
			m_array(NULL),
			m_size(0)
		{}

		Array(unsigned int size) :
			m_array(NULL),
			m_size(size)
		{
			if (size == 0)
				return ;
			this->m_array = new T[size];
		}

		~Array()
		{
			if (this->m_array)
				delete[] this->m_array;
		}
		
		unsigned int	size(void) const
		{
			return this->m_size;
		}

		Array(Array &copy) : m_size(copy.m_size)
		{
			if (copy.m_size > 0)
				this->m_array = new T[copy.m_size];
			else
				this->m_array = NULL;
			for (unsigned int i = 0; i < copy.m_size; i++)
				this->m_array[i] = copy.m_array[i];
		}

		Array & operator = (Array &s)
		{
			if (&s != this)
			{
				if (this->m_array)
					delete[] this->m_array;
				if (s.m_size > 0)
					this->m_array = new T[s.m_size];
				else
					this->m_array = NULL;
				for (unsigned int i = 0; i < s.m_size; i++)
					this->m_array[i] = s.m_array[i];
			}
			return *this;
		}

		T & operator [] (unsigned int i) const
		{
			if (this->m_array && i < this->m_size)
				return (this->m_array[i]);
			else
				throw std::exception();
		}
};

#endif
