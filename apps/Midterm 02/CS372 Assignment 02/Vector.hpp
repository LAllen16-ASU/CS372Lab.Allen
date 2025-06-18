#pragma once
#include <iostream>
#include <algorithm>

template<typename T>
class Vector {
private:
	int vIndex;

	bool operator== (Vector& other) const {
		if (other.size() != length)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				if (arr[i] != other.at(i))
				{
					return false;
				}
			}
		}
		return true;
	}
	bool operator[](int i) {
		if ((i < 0) || (i >= length))
		{
			std::cerr << "Vector: index out of bounds." << std::endl;
			exit(1);
		}
		return arr[i];
	}
	Vector& operator=(const Vector& source)
	{
		arr = new T[source.vCapacity];
		vCapacity = source.vCapacity;
		length = source.length;
		for (int i = 0; i < source.size(); i++)
		{
			arr[i] = source.arr[i];
		}
	}
public:
	int length;
	int vCapacity;
	T* arr;

	class const_iterator {
		
	};

	class Iterator {
	private:
		T* iter;
		
	public:
		Iterator(T* iter) : iter(iter) {}

		T& operator*() const 
		{
			return *iter;
		}

		Iterator operator++(int)
		{
			Iterator temp = *this;
			++iter;
			return temp;
		}

		Iterator& operator++()
		{
			++iter;
			return *this;
		}

		bool operator==(const Iterator& other)
		{
			return iter == other.iter;
		}

		bool operator!=(const Iterator& other)
		{
			return iter != other.iter;
		}

	};

	Iterator begin()
	{
		return Iterator(arr);
	}
	Iterator end()
	{
		return Iterator(arr + length);
	}
	

	// function declarations
	void expand(int newCapacity);
	void put(T data, int index);
	virtual void push_back(T data);
	T& at(int index);
	int size();
	virtual int capacity();
	void traverse();

	// constructors
	Vector() {
		arr = new T[1];
		vCapacity = 1;
		length = 0;
		vIndex = 0;
	}
	~Vector() {
		
		delete[] arr;
	}
	Vector(Vector& obj)
	{
		this->arr = new T[obj.capacity()];
		for (int i = 0; i < obj.size(); i++)
		{
			this->put(i, obj.at(i));
		}
	}
};

// expand function ensures there is always capacity for the push_back function to push elements into.
template<typename T>
void Vector<T>::expand(int newCapacity) {
	if (newCapacity > vCapacity)
	{
		T* temp = new T[newCapacity];
		std::copy(arr, arr + capacity(), temp);
		vCapacity = newCapacity;
		arr = temp;
		temp = nullptr;
	}
	else
	{
		std::cerr << "vector::expand: new capacity is less than or equal to current capacity\n";
	}
}

// put function inserts an element into an index of the vector
template<typename T>
void Vector<T>::put(T data, int index) {
	if (index == vCapacity)
	{
		push_back(data);
	}
	else
	{
		arr[index] = data;
	}
}

// push_back function adds an element to the end of the vector
template<typename T>
void Vector<T>::push_back(T data) {
	if (length == capacity()) {
		expand(2 * capacity());
	}
	arr[length] = data;
	length++;
}

// traverse function outputs the vector contents
template<typename T>
void Vector<T>::traverse()
{
	std::cout << "[ ";
	for (Vector<T>::Iterator it = this->begin(); it != this->end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "]" << std::endl;
}

// at function returns the value at a certain index in the vector
template<typename T>
T& Vector<T>::at(int index)
{
	if (index < 0 || index >= length)
	{
		std::cerr << "Vector: index out of bounds on access" << std::endl;
		exit(1);
	}
	else
	{
		return arr[index];
	}
}

// getter function for the vCapacity variable
template<typename T>
int Vector<T>::capacity()
{
	return vCapacity;
}

// getter function for the length variable
template<typename T>
int Vector<T>::size()
{
	return length;
}
