#include <iostream>
#include <functional>

template <typename T>
class List 
{
protected:
	struct Node
	{
		T data;
		Node* prev;
		Node* next;
		bool isHidden = false;
	};
	Node* head;
	Node* tail;
public:
	class const_iterator
	{
	protected:
		Node* current;
		T& retrieve() const { return current->data; }
		const_iterator(Node* p) : current(p) {}
		friend class List<T>;
	public:
		const_iterator() : current(nullptr) {}
		T& operator*() const { return retrieve(); }
		const_iterator& operator++() { current = current->next; return *this; }
		const_iterator operator++(int) { const_iterator old = *this; ++(*this); return old; }
		bool operator==(const const_iterator& rhs) const { return current == rhs.current; }
		bool operator!=(const const_iterator& rhs) const { return !(*this == rhs); }
	};

	class iterator : public const_iterator
	{
	protected:
		iterator(Node* p) : const_iterator(p) {}
		friend class List<T>;
	public:
		iterator() {}
		T& operator*() { return const_iterator::retrieve(); }
		const T& operator*() const { return const_iterator::operator*(); }
		iterator& operator++() { this->current = this->current->next; return *this; }
		iterator operator++(int) { iterator old = *this; ++(*this); return old; }
	};

	iterator begin() const { return { head->next }; }
	iterator end() const { return tail; }
	const_iterator cbegin() const { return { head->next }; }
	const_iterator cend() const { return tail; }

	List();
	List(T newData);
	List(List& rhs);
	~List();
	List(List&& rhs);
	List<T>& operator=(const List<T>& rhs);
	List<T>& operator=(List<T>&& rhs);
	bool isEmpty() const;
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();
	virtual void setupList();
	void clearList();
	virtual void printTheList();
	T front();
	T back();
	virtual void traverse(std::function<void(T& data)> doIt);
};

// Helper Functions
template<typename T>
void List<T>::setupList()
{
	head = new Node();
	tail = new Node();
	head->prev = nullptr;
	tail->next = nullptr;
	head->next = tail;
	tail->prev = head;
	head->isHidden = true;
	tail->isHidden = true;
}

template <typename T>
void List<T>::clearList()
{
	Node* current = head->next;
	while (!isEmpty())
	{
		pop_back();
		current = current->next;
	}
}

template <typename T>
void List<T>::printTheList()
{
	if (head->next == tail)
	{
		std::cout << "The list is empty." << std::endl;
	}
	else
	{
		traverse([](T& data) { std::cout << data << " ";});
		std::cout << std::endl;
	}
}

template <typename T>
void List<T>::traverse(std::function<void(T& data)> doIt)
{ 
	Node* current = head->next;
	while (current != tail)
	{
		doIt(current->data);
		current = current->next;
	}
}

template <typename T>
bool List<T>::isEmpty() const
{
	return (head->next == tail && tail->prev == head);
}

// Constructors and Destructors
template <typename T>
List<T>::List()
{
	setupList();
}

template <typename T>
List<T>::List(T newData)
{
	setupList();
	push_back(newData);
}

template <typename T>
List<T>::~List()
{
	clearList();
	delete head;
	delete tail;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
List<T>::List(List& rhs)
{
	setupList();
	Node* current = rhs.head->next;
	while (current != rhs.tail)
	{
		push_back(current->data);
		current = current->next;
	}
}

template <typename T>
List<T>::List(List&& rhs)
{
	head = rhs.head;
	tail = rhs.tail;
	rhs.head = nullptr;
	rhs.tail = nullptr;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& rhs)
{
	if (this != &rhs)
	{
		clearList();
		Node* current = rhs.head->next;
		while (current != rhs.tail)
		{
			push_back(current->data);
			current = current->next;
		}
	}
	return *this;
}

template <typename T>
List<T>& List<T>::operator=(List<T>&& rhs)
{
	if (this != &rhs)
	{
		clearList();
		delete head;
		delete tail;
		head = rhs.head;
		tail = rhs.tail;
		rhs.head = nullptr;
		rhs.tail = nullptr;
	}
	return *this;
}
// Member Functions
// Push and Pop
template <typename T>
void List<T>::push_front(T data)
{
	if (this->isEmpty())
	{
		std::cout << "List was empty, setting up list..." << std::endl;
		setupList();
		Node* actualHead = new Node();
		actualHead->data = data;
		actualHead->prev = head;
		actualHead->next = tail;
		tail->prev = actualHead;
		head->next = actualHead;
		
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
}

template <typename T>
void List<T>::push_back(T data)
{
	if (isEmpty())
	{
		std::cout << "List was empty, setting up list..." << std::endl;
		setupList();
		Node* actualTail = new Node();
		actualTail->data = data;
		actualTail->prev = head;
		actualTail->next = tail;
		tail->prev = actualTail;
		head->next = actualTail;
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
}

template <typename T>
void List<T>::pop_front()
{
	if (!isEmpty())
	{
		Node* firstNode = head->next;
		head->next = firstNode->next;
		Node* newFirstNode = head->next;
		newFirstNode->prev = head;
		delete firstNode;
		firstNode = nullptr;
	}
	else
	{
		std::cerr << "pop_front(): Attempt to pop from an empty list." << std::endl;
	}
}

template <typename T>
void List<T>::pop_back()
{
	if (!isEmpty())
	{
		Node* lastNode = tail->prev;
		tail->prev = lastNode->prev;
		Node* newLastNode = tail->prev;
		newLastNode->next = tail;
		delete lastNode;
		lastNode = nullptr;
	}
	else
	{
		std::cerr << "pop_back(): Attempt to pop from an empty list." << std::endl;
	}
}
// Front and Back

template <typename T>
T List<T>::front()
{
	Node* actualHead = head->next;
	return (actualHead->data);
}

template <typename T>
T List<T>::back()
{
	Node* actualTail = tail->prev;
	return (actualTail->data);
}
