#include <iostream>

template <typename Thing>
class ReceiptBag : public Bag<Thing>
{
private:
	std::vector<int> receipts;
	std::vector<Thing> things;
	int bagSize = 0;
public:
	ReceiptBag() = default;
	void insert(Thing aThing) override;
	void printReceipts() const;
	void printContents() const;
	void remove(int receipt);
};

template <typename Thing>
void ReceiptBag<Thing>::insert(Thing aThing)
{
	std::cout << "Inserting item: " << aThing << " with receipt: " << bagSize << std::endl;
	things.push_back(aThing);
	receipts.push_back(bagSize);
	bagSize++;
}

template <typename Thing>
void ReceiptBag<Thing>::printReceipts() const
{
	std::cout << "Receipts: [ ";
	for (const auto& receipt : receipts)
	{
		std::cout << receipt << " ";
	}
	std::cout << "]" << std::endl << std::endl;
}

template <typename Thing>
void ReceiptBag<Thing>::printContents() const
{
	std::cout << "Contents: [ ";
	for (const auto& thing : things)
	{
		std::cout << thing << " ";
	}
	std::cout << "]" << std::endl << std::endl;
}

template <typename Thing>
void ReceiptBag<Thing>::remove(int receipt)
{
	if (receipt < 0 || receipt >= bagSize)
	{
		std::cerr << "ReceiptBag::remove: Invalid receipt number." << std::endl;
	}
	else
	{
		std::cout << "Removing item: " << things[receipt] << " with receipt: " << receipt << std::endl;
		things.erase(things.begin() + receipt);
		receipts.erase(receipts.begin() + receipt);
	}
}