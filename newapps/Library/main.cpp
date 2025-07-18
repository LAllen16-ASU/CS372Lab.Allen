#include <iostream>
#include "Vector.hpp"
#include "VectorPoly.hpp"
#include "VectorPoly2.hpp"
#include "Array.hpp"
#include "Bag.hpp"
#include "ReceiptBag.hpp"

int main()
{
	ReceiptBag<int> rBag = ReceiptBag<int>();
	rBag.insert(5);
	rBag.insert(9);
	rBag.insert(15);
	std::cout << std::endl;
	rBag.printReceipts();
	rBag.printContents();
	rBag.remove(1);
	rBag.printReceipts();
	rBag.printContents();
	/*
	Array<int> myArray = Array<int>(5);
	std::cout << "Size: " << myArray.size() << std::endl;
	myArray.append(1);
	myArray.append(5);
	myArray.append(99);
	myArray.append(23);
	myArray.append(42);
	//myArray.append(100);
	for (int i = 0; i < myArray.size(); i++)
	{
		std::cout << myArray[i] << std::endl;
	}

	Vector<int> vec = Vector<int>();
	vec.push_back(5);
	std::cout << vec.capacity() << std::endl;
	std::cout << vec[0] << std::endl;

	VectorPoly<int> vec2 = VectorPoly<int>();
	vec2.push_back(10);
	vec2.push_back(2);
	vec2.push_back(3);
	std::cout << vec2.capacity() << std::endl;
	std::cout << vec2[0] << std::endl;

	VectorPoly2<int> vec3 = VectorPoly2<int>(128);
	vec3.push_back(9);
	std::cout << vec3.capacity() << std::endl;
	std::cout << vec3[0] << std::endl;
	*/
}