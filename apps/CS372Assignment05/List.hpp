#pragma once
#include <iostream>

template <typename T>
class List
{
private:
	class Node
	{
	public:
		T data = 0;
		std::shared_ptr<Node()> prev;
		std::shared_ptr<Node()> next;
		bool isHiddenNode = false;
	};

	std::shared_ptr<Node()> head;
	std::shared_ptr<Node()> tail;

public:

};