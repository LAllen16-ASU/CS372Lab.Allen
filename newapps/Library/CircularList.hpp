#pragma once
#include "List.hpp"
#include <functional>

template <typename T>
class CircularList : public List<T>
{
public:
	void setupList() override
	{
		this->head = new Node();
		this->tail = this->head;
	}

	T peekTail()
	{
		return this->tail->next->data;
	}

	T peekHead()
	{
		return this->head->prev->data;
	}
};



