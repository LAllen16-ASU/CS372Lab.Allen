#include <iostream>
#include <vector>

template <typename Thing>
class Bag
{
private:
	std::vector<Thing> things;
	int bagSize = 0;
public:
	Bag() = default;
	Bag(const Bag& other) = default;
	virtual void insert(Thing aThing);
	Thing& pop();
	int size() const;
	int count(Thing aThing);
};

template <typename Thing>
void Bag<Thing>::insert(Thing aThing)
{
	things.push_back(aThing);
	bagSize++;
}

template <typename Thing>
Thing& Bag<Thing>::pop()
{
	if(bagSize != 0)
	{
		Thing& item = things.back();
		things.pop_back();
		bagSize--;
		return item;
	}
	else
	{
		std::cerr << "Bag::pop: Bag is empty, cannot pop item." << std::endl;
	}
	
}

template <typename Thing>
int Bag<Thing>::size() const
{
	return bagSize;
}

template <typename Thing>
int Bag<Thing>::count(Thing aThing)
{
	int count = 0;
	for (const auto& item : things)
	{
		if(item == aThing)
		{
			count++;
		}
	}
}
