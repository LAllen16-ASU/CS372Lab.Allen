// CS372 Assignment 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.hpp"
#include "PolyVector.hpp"
#include "Array.hpp"
#include <chrono>


void addElements(Vector<int>&, int&);

int main()
{
    int numElements = 0;
    Vector<int> myVector;
    std::cout << "Enter a number of elements: ";
    std::cin >> numElements;
    addElements(myVector, numElements);
    std::cout << "Traverse using iterators: ";
    myVector.traverse();
    
}


void addElements(Vector<int>& nv, int& n)
{
    for (int i = 0; i < n; i++)
    {
        nv.push_back(i);
    }
}