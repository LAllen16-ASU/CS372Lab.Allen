#pragma once
#include "Vector.hpp"
#include <iostream>

template <typename T>
class VectorPoly2 : public Vector<T>
{
public:
    VectorPoly2(int initialCapacity = 128) : Vector<T>(initialCapacity) {}
    void expand(int newCapacity) override;
    void push_back(T data) override;
};

template <typename T>
void VectorPoly2<T>::expand(int newCapacity)
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

template <typename T>
void VectorPoly2<T>::push_back(T data)
{
    if (length == vCapacity)
    {
        expand(4 * vCapacity);
    }
    arr[length] = data;
    length++;
}