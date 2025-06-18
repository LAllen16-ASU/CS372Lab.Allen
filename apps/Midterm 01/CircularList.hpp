#pragma once
#include <iostream>
#include "List.hpp"

template <typename T>
class CircularList : public List<T>
{
private:
	class Node
	{
	public:
		T data;
		Node* prev;
		Node* next;
		bool isHiddenNode = false;
	};
	Node* head;
	Node* tail;

	class const_iterator
	{
	protected:
		Node* current;
		T& retrieve() const { return current->data; }
		const_iterator(Node* p) : current(p) {}
		friend class List<T>;
	public:
		const_iterator() : current(nullptr) {}
		T& operator*() const
		{
			return retrieve();
		}
		const_iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		const_iterator operator++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}
		bool operator==(const const_iterator& rhs) const
		{
			return current == rhs.current;
		}
		bool operator!=(const const_iterator& rhs) const
		{
			return !(*this == rhs);
		}
	};
	class iterator : public const_iterator
	{
	protected:
		iterator(Node* p) : const_iterator(p) {}
		friend class List<T>;
	public:
		iterator() {}
		T& operator*()
		{
			return const_iterator::retrieve();
		}
		const T& operator*() const
		{
			return const_iterator::operator*();
		}
		iterator& operator++()
		{
			this->current = const_iterator::current->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
	};


public:
	CircularList() : List() {}
	~CircularList() {}

	void traverse(void (*doIt)(T data)) override
	{
		Node* startingPoint = tail;
		Node* current = head->next;
		while (current != startingPoint)
		{
			doIt(current->data);
			current = current->next;
			if (current == startingPoint)
			{
				current = head->next;
			}
		}
	}
};