#include <iostream>


template <typename T>
class Array
{
public:
	Array();
	Array(size_t size);
	~Array();
	Array(Array& other);
	void append(T data);
	T& operator[](int index);
	Array& operator=(const Array& other);
	int size();
protected:
	T* arr = new T[1];
	size_t vSize = 1;
	int length = 0;
	int filled = 0;
};

template <typename T>
Array<T>::Array()
{
	arr = new T[1];
	vSize = 1;
	length = 0;
}

template <typename T>
Array<T>::Array(size_t size)
{
	if (size <= 0)
	{
		std::cerr << "Array::Array: initial size must be greater than 0" << std::endl;
		exit(1);
	}
	arr = new T[size];
	vSize = size;
	length = size;
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
	arr = nullptr;
}

template <typename T>
Array<T>::Array(Array& other)
{
	this->arr = new T[other.vSize];
	this->vSize = other.vSize;
	this->length = other.length;
	for (int i = 0; i < other.length; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

template <typename T>
int Array<T>::size()
{
	return vSize;
}

template <typename T>
void Array<T>::append(T data)
{
	if (filled >= size())
	{
		std::cerr << "Array::append: array size exceeded" << std::endl;
		exit(1);
	}
	arr[filled] = data;
	if (filled < size()) { filled++; }
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if ((index < 0) || (index >= length))
	{
		std::cerr << "Array::operator[]: index out of bounds" << std::endl;
		exit(1);
	}
	else
	{
		return arr[index];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] arr;
	this->arr = new T[other.vSize];
	this->vSize = other.vSize;
	this->length = other.length;
	for (int i = 0; i < other.length; i++)
	{
		this->arr[i] = other.arr[i];
	}
	return *this;
}