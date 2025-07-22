#include <iostream>
#include <vector>
#include <List.hpp>

template <typename Thing>
class ListBag
{
private:
	List<Thing> things;
	int bagSize = 0;
public:
	ListBag() = default;
	ListBag(const ListBag& other) = default;
	virtual void insert(Thing aThing);
	Thing& pop();
	int size() const;
	int count(Thing aThing);
};

template <typename Thing>
void ListBag<Thing>::insert(Thing aThing)
{
	things.push_back(aThing);
	bagSize++;
}

template <typename Thing>
Thing& ListBag<Thing>::pop()
{
	if (bagSize != 0)
	{
		Thing& item = things.back();
		things.pop_back();
		bagSize--;
		return item;
	}
	else
	{
		std::cerr << "ListBag::pop: ListBag is empty, cannot pop item." << std::endl;
	}

}

template <typename Thing>
int ListBag<Thing>::size() const
{
	return bagSize;
}

template <typename Thing>
int ListBag<Thing>::count(Thing aThing)
{
	int count = 0;
	for (const auto& item : things)
	{
		if (item == aThing)
		{
			count++;
		}
	}
}
