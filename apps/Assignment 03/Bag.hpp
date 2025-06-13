#pragma once
#include <iostream>
#include "List.hpp"

template <typename T>
class Bag 
{
private:
	List<T> contents;
public:
	Bag() {}
	void insert(T data)
	{
		contents.push_back(data);
	}
	void pop()
	{
		contents.pop_back();
	}

	void print()
	{
		contents.printTheList();
	}
};