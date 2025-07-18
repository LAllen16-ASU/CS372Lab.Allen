#pragma once
#include <iostream>
#include <algorithm> // for std::copy

template <typename T>
class Vector
{
public:
	Vector();
	Vector(int initialCapacity);
	~Vector();
	Vector(Vector& other);
	void put(T data, int pos);
	virtual void expand(int newCapacity);
	virtual void push_back(T data);
	T& at(int index);
	int size();
	int capacity();
	void traverse();
	T& operator[](int index);
	Vector& operator=(const Vector& other);
protected:
	T* arr = new T[1];
	int vCapacity = 1;
	int length = 0;
};

template <typename T>
Vector<T>::Vector()
{

	arr = new T[1];
	vCapacity = 1;
	length = 0;
}

template <typename T>
Vector<T>::Vector(int initialCapacity)
{
		if (initialCapacity <= 0)
	{
		std::cerr << "vector::vector: initial capacity must be greater than 0" << std::endl;
		exit(1);
	}
	arr = new T[initialCapacity];
	vCapacity = initialCapacity;
	length = initialCapacity - 1;
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] arr;
	arr = nullptr;
}

template <typename T>
Vector<T>::Vector(Vector& other)
{
	this->arr = new T[other.capacity()];
	for (int i = 0; i < other.size(); i++)
	{
		this->put(i, obj.at(i));
	}
}

template <typename T>
void Vector<T>::expand(int newCapacity)
{
	if (newCapacity > vCapacity)
	{
		T* temp = new T[newCapacity];
		for (int i = 0; i < length; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		vCapacity = newCapacity;
		arr = temp;
	}
	else
	{
		std::cerr << "vector::expand: new capacity is less than or equal to current capacity" << std::endl;
	}
}

template <typename T>
void Vector<T>::put(T data, int pos)
{
	if (pos == vCapacity)
	{
		push_back(data);
	}
	else
	{
		arr[pos] = data;
	}
}

template <typename T>
void Vector<T>::push_back(T data)
{
	if (length == vCapacity)
	{
		expand(2 * vCapacity);
	}
	arr[length] = data;
	length++;
}

template <typename T>
void Vector<T>::traverse()
{
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
}

template <typename T>
T& Vector<T>::at(int index)
{
	if (index < 0 || index > length)
	{
		std::cerr << "vector::at: index out of bounds" << std::endl;
		exit(1);
	}
	else
	{
		return arr[index];
	}
}

template <typename T>
int Vector<T>::size()
{
	return length;
}

template <typename T>
int Vector<T>::capacity()
{
	return vCapacity;
}

template <typename T>
T& Vector<T>::operator[](int index)
{
	if ((index < 0) || (index >= length))
	{
		std::cerr << "vector::operator[]: index out of bounds" << std::endl;
		exit(1);
	}
	else
	{
		return at(index);
	}
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	delete[] arr;
	arr = new T[1];
	vCapacity = 1;
	length = 1;
	for (int i = 0; i < obj.size(); i++)
	{
		push_back(obj.at(i));
	}
	return *this;
}