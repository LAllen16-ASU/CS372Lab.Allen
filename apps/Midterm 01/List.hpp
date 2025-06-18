#pragma once
#include <iostream>

template <typename T>
class List 
{
private:
	class Node
	{
	public:
		T data;
		Node* prev;
		Node* next;
		bool isHiddenNode = false;
		bool isDeleted = false;
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


	void setUpList()
	{
		Node* newNode = new Node();
		newNode->next = tail;
		newNode->prev = head;
		head->next = newNode;
		tail->prev = newNode;

	}

	void deleteListContents()
	{
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr)
		{
			temp = current->next;
			delete current;
			current = temp;
		}
	}

	iterator begin() const { return { head->next }; }
	iterator end() const { return { tail }; }
	const_iterator cbegin() const { return { head->next }; }
	const_iterator cend() const { return { tail }; }
public:

	int deletedNodes = 0;
	int tangibleNodes = 0;

	bool empty() const { return (head->next == tail); }

	T& operator[](int index)
	{
		if (index < 0 || index >= tangibleNodes)
		{
			std::cerr << "List: Index out of Range." << std::endl;
		}
		else
		{
			Node* current = head->next;
			for (int i = 0; i < index; ++i)
			{
				current = current->next;
			}
			return current->data;
		}
	}

	T front()
	{
		Node* actualHead = head->next;
		return (actualHead->data);
	}
	T back()
	{
		Node* actualTail = tail->prev;
		return (actualTail->data);
	}

	List()
	{
		head = new Node();
		head->isHiddenNode = true;
		tail = new Node();
		tail->isHiddenNode = true;
		head->prev = nullptr;
		head->next = tail;
		tail->prev = head;
		tail->next = nullptr;
	}
	List(T newData)
	{
		head->data = newData;
	}

	List(List& rhs)
	{
		deleteListContents();
		head = rhs.head;
		tail = rhs.tail;
	}

	List(List&& list)
	{
		head->data = list->head->data;
		tail->data = list->tail->data;
		list->head->data = nullptr;
		list->tail->data = nullptr;
	}

	~List()
	{
		deleteListContents();
	}

	void push_front(T data)
	{
		if (this->empty())
		{
			setUpList();
			Node* actualHead = head->next;
			actualHead->data = data;
		}
		else
		{
			Node* actualHead = head->next;
			Node* newNode = new Node();
			newNode->data = data;
			newNode->next = actualHead;
			actualHead->prev = newNode;
			newNode->prev = head;
			head->next = newNode;
		}
		tangibleNodes += 1;
	}
	
	void push_back(T data)
	{
		if (this->empty())
		{
			setUpList();
			Node* actualTail = tail->prev;
			actualTail->data = data;
		}
		else
		{
			Node* actualTail = tail->prev;
			Node* newNode = new Node();
			newNode->data = data;
			newNode->prev = actualTail;
			actualTail->next = newNode;
			newNode->next = tail;
			tail->prev = newNode;
		}
		tangibleNodes += 1;
		
	}

	void pop_back()
	{
		if (!empty())
		{
			lazyDeleteItem(tail->prev);
		}
		else
		{
			std::cerr << "pop_back() attempt to pop from an empty list." << std::endl;
		}
		
	}
	
	void pop_front()
	{
		if (!empty())
		{
			lazyDeleteItem(head->next);
		}
		else
		{
			std::cerr << "pop_front() attempt to pop from an empty list." << std::endl;
		}
	}

	void printTheList()
	{
		Node* current = head->next;
		while (current != tail && !current->isDeleted)
		{
			std::cout << current->data << " ";
			Node* tempNode = new Node();
			tempNode = current;
			current = current->next;
			current->prev = tempNode;
			tempNode = nullptr;
			delete tempNode;
		}
		std::cout << std::endl;
	}


	void lazyDeleteItem(Node* n)
	{
		n->isDeleted = true;
		deletedNodes += 1;
		tangibleNodes -= 1;
	}

	void fullDelete()
	{
		Node* current = head->next;
		while (current != tail)
		{
			if (current->isDeleted)
			{
				deletedNodes -= 1;
				current->next->prev = current->prev;
				current->prev->next = current->next;
			}
			current = current->next;
		}
	}

	virtual void traverse(void (*doIt)(Node* c))
	{
		Node* current = head->next;
		while (current != tail)
		{
			doIt(current);
			current = current->next;
		}
	}
};