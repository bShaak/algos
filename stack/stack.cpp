#include <iostream>
#include <vector>

template<typename T>
class Stack
{
private:
	std::vector<T> data;

public:
	void pop()
	{
		if(!data.empty())
			data.pop_back();
	}

	void push(T elem)
	{
		data.push_back(elem);
	}

	T top()
	{
		if(!data.empty())
			return data.back();
	}
}