#include <iostream>
#include <vector>
#include <algorithm>

template <size_t n> class permutation
{
private:
	std::vector<size_t> numbers;

public:
	permutation()
	{
		numbers.reserve(n);
	}
	permutation(unsigned* array)
	{
		const size_t size_array = sizeof(array) / sizeof(unsigned);
		numbers.reserve(size_array);
		for (int i = 0; i < size_array; i++)
		{
			numbers[i] = array[i];
		}
	}
	permutation(const permutation& other)
	{
		for (int i = 0; i < n; i++)
		{
			this->numbers[i] = other.numbers[i];
		}
	}
	std::vector<size_t> prev()
	{
		int l = this->numbers.size();
		if (l <= 1)
		{
			return this->numbers;
		}
		int i = l - 2;
		while (i >= 0 && this->numbers[i] <= this->numbers[i + 1])
		{
			i--;
		}
		if (i < 0)
		{
			return this->numbers;
		}
		int j = l - 1;
		while (j > 1 && this->numbers[j] >= this->numbers[i] || this->numbers[j] == this->numbers[j - 1])
		{
			j--;
		}
		std::swap(this->numbers[j], this->numbers[i]);
		return this->numbers;
	}
	std::vector<size_t> next()
	{
		int l = this->numbers.size();
		if (l <= 1)
		{
			return this->numbers;
		}
		int i = l - 2;
		while (this->numbers[i - 1] >= this->numbers[i])
		{
			if (i-- == 0)
			{
				return this->numbers;
			}
		}
		int j = l - 1;
		while (j > i && this->numbers[j] <= this->numbers[i - 1])
		{
			j--;
		}
		std::swap(this->numbers[i - 1], this->numbers[j]);
		return this->numbers;
	}
	std::vector<size_t> inverse() const
	{
		size_t size = this->numbers.size();
		std::vector<size_t> inverse_vector(size);
		for (int i = 0; i < size; i++)
		{
			inverse_vector[this->vector[i] - 1] = i + 1;
		}
		return inverse_vector;
	}
	permutation& operator=(const permutation& other)
	{
		for (int i = 0; i < n; i++)
		{
			this->numbers[i] = other.numbers[i];
		}
		return *this;
	}
	permutation& operator*(const permutation& other)
	{
		std::vector<size_t> copy_this_numbers(n);
		for (int i = 0; i < n; i++)
		{
			copy_this_numbers[i] = this->numbers[i];
		}
		for (int i = 0; i < n; i++)
		{
			this->numbers[i] = other.numbers[copy_this_numbers[i]];
		}
		delete[] copy_this_numbers;
		return *this;
	}
	permutation& operator++()
	{
		next();
		return *this;
	}
	permutation& operator++(int)
	{
		next();
		return *this;
	}
	permutation& operator--()
	{
		prev();
		return *this;
	}
	permutation& operator--(int)
	{
		prev();
		return *this;
	}
	permutation& operator()(unsigned* values)
	{
		for (int i = 0; i < n; i++)
		{
			int next = i;
			while (values[next] >= 0)
			{
				std::swap(this->numbers[i], this->numbers[values[next]]);
				int temp = values[next];
				values[next] -= n;
				next = temp;
			}
		}
		return *this;
	}

	bool operator==(const permutation& other)
	{
		for (int i = 0; i < n; i++)
		{
			if (this->numbers[i] != other.numbers[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator!=(const permutation& other)
	{
		for (int i = 0; i < n; i++)
		{
			if (this->numbers[i] != other.numbers[i])
			{
				return true;
			}
		}
		return false;
	}
	bool operator>(const permutation& other)
	{
		for (int i = n - 1; i >= 0; i++)
		{
			if (this->numbers[i] > other.numbers[i])
			{
				return true;
			}
		}
		return false;
	}
	bool operator<(const permutation& other)
	{
		for (int i = n - 1; i >= 0; i++)
		{
			if (this->numbers[i] < other.numbers[i])
			{
				return true;
			}
		}
		return false;
	}
	bool operator>=(const permutation& other)
	{
		return ((*this > other) || (*this == other));
	}
	bool operator<=(const permutation& other)
	{
		return ((*this < other) || (*this == other));
	}

	size_t& operator[](size_t index)
	{
		return this->numbers[index];
	}
	const size_t& operator[] (size_t index) const
	{
		return this->numbers[index];
	}

};
