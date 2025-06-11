// CS372 Assignment 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.hpp"
#include "PolyVector.hpp"
#include "Array.hpp"
#include <chrono>


void vecTest(Vector<int>&);
void addElements(Vector<int>&, int&);
void ArrTest();

int main()
{
    Vector<int> newVector;
    PolyVector<int> pVector;
    vecTest(newVector);
    vecTest(pVector);

    std::cout << "Capacity Vector: " << newVector.capacity() << std::endl;
    std::cout << "Capacity PolyVector: " << pVector.capacity() << std::endl;
    
}


void addElements(Vector<int>& nv, int& n)
{
    for (int i = 0; i < n; i++)
    {
        nv.push_back(i);
    }
}

void vecTest(Vector<int>& vec)
{
    int numElements = 0;
    std::cout << "Timing the Vector" << std::endl << std::endl;
    std::cout << "Enter a number of elements to add to the vector: ";
    std::cin >> numElements;
    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed_seconds = end - start;
    addElements(vec, numElements);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start;
    std::cout << "Elapsed time: " << elapsed_seconds.count() << "ms\n";
}

void ArrTest()
{
    Array<int> myArray(5);
    myArray[0] = 1;
    myArray[1] = 2;
    myArray[2] = 3;
    myArray[3] = 4;
    myArray[4] = 5;
    myArray.traverse();
    myArray.push_back(3);
    myArray.traverse();
    myArray.pop_back();
    myArray.traverse();
    myArray.pop_back();
    myArray.traverse();
}