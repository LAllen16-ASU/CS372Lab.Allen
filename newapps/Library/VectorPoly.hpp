#pragma once
#include <iostream>
#include "Vector.hpp"

template <typename T>
class VectorPoly : public Vector<T>
{
public:
	void expand(int newCapacity) override;
};

template <typename T>
void VectorPoly<T>::expand(int newCapacity)
{
    if (newCapacity > this->vCapacity)
    {
        T* temp = new T[newCapacity];
        std::copy(arr, arr + vCapacity, temp);
        delete[] arr;
        vCapacity = newCapacity;
        arr = temp;
    }
    else
    {
        std::cerr << "VectorQ1::expand: new capacity is less than or equal to current capacity" << std::endl;
    }
}

