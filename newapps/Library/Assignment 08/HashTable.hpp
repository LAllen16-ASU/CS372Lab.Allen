#include <iostream>
#include <list>
#include <cstring>
#include <vector>
#include <functional>

using std::list;
using std::vector;
using std::hash;

template <typename RecordType>
class HashTable
{

public:
	static const std::size_t CAPACITY = 811;
	HashTable() = default;
	void insert(const RecordType& entry);
	void remove(int key);
	bool isPresent(int key) const;
	void find(int key, bool& found, RecordType& result) const;
	std::size_t size() const { return used; }
	void printTable();
private:
	list<RecordType> data[CAPACITY];
	std::size_t totalRecords;
	std::size_t hash(int key) const;
};

template<typename RecordType>
void HashTable<RecordType>::insert(const RecordType& entry)
{
	int key = hash(entry);
	data[key].push_back(entry);
}

template<typename RecordType>
void HashTable<RecordType>::remove(int key)
{

}

template<typename RecordType>
void HashTable<RecordType>::find(int key, bool& found, RecordType& result) const
{

}

template<typename RecordType>
bool HashTable<RecordType>::isPresent(int key) const
{

}

template<typename RecordType>
std::size_t HashTable<RecordType>::hash(int key) const
{
	return key % 10;
	
}

template<typename RecordType>
void HashTable<RecordType>::printTable()
{
	for (int i = 0; i < data->size(); i++)
	{
		std::list<RecordType> l = data[i];
		for (RecordType value : l)
		{
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}
}





