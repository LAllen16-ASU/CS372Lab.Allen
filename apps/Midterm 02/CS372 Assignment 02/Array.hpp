#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
	int size;
	T* arr;

	

public:
	Array(int size_t)
	{
		this->size = size_t;
		arr = new T[size_t];
	}
	~Array()
	{
		delete[] arr;
	}
	int getSize();
	void push_back(T data);
	void pop_back();
	void traverse();

	T& operator[](std::size_t index) const
	{
		if (index >= size || index < 0)
		{
			std::cerr << "Array: index out of bounds." << std::endl;
			exit(1);
		}
		return arr[index];
	}
};

template <typename T>
int Array<T>::getSize()
{
	return this->size;
}

template <typename T>
void Array<T>::push_back(T data)
{
	T* temp = arr;
	arr = new T[this->size + 1];
	this->size += 1;
	for (int i = 0; i < this->size-1; i++)
	{
		arr[i] = temp[i];
	}
	arr[this->size - 1] = data;
}

template <typename T>
void Array<T>::pop_back()
{
	T* temp = arr;
	arr = new T[this->size - 1];
	this->size -= 1;
	for (int i = 0; i < this->size; i++)
	{
		arr[i] = temp[i];
	}
}

template<typename T>
void Array<T>::traverse()
{
	std::cout << "[ ";
	for (int i = 0; i < this->size; i++)
	{
		if (i == this->size - 1)
		{
			std::cout << arr[i] << " ]" << std::endl;
		}
		else
		{
			std::cout << arr[i] << ", ";
		}
	}
}

