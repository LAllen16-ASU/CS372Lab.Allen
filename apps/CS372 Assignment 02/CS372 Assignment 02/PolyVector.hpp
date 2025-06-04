#pragma once
#include <iostream>
#include "Vector.hpp"

template <typename T>
class PolyVector : public Vector<T>
{
public:
	// Constructor sets initial capacity to 128
	PolyVector() : Vector<T>() {
		this->vCapacity = 128;
	}

	void push_back(T data) override;
	int capacity() override;
};

// Override the push_back function to increase capacity by 4x instead of 2x when exceeded.
template <typename T>
void PolyVector<T>::push_back(T data)  {
	if (this->length == capacity()) {
		this->expand(4 * capacity());
		//std::cout << "Capacity of pVector: " << capacity() << std::endl;
	}
	this->arr[this->length] = data;
	this->length++;
}

template <typename T>
int PolyVector<T>::capacity()
{
	return this->vCapacity;
}
