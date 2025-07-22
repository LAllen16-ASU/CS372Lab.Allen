#include <iostream>
#include "Assignment 08/HashTable.hpp"
#include <list>
using std::list;
using std::string;

void popTable(HashTable<int>& arr, vector<int> data);

int main()
{
	vector<int> data = {5, 50, 99, 21, 20, 25, 35};
	HashTable<int> arr;
	std::cout << "Size of Data: " << data.size() << std::endl;
	popTable(arr, data);
	arr.printTable();

	return 0;
}

void popTable(HashTable<int>& arr, vector<int> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		arr.insert(data[i]);
	}
}

/*
int main()
{
	vector<string> names = { "Larry", "John", "Kevin", "Alex", "Bob" };
	vector<int> path = { 0, 1, 2, 3, 4, 0 }; // Example invalid cycle with repeated node

	Graph<string> g(names, false);
	g.addEdge(0, 1); // Larry - John
	g.addEdge(1, 2); // John - Alex
	g.addEdge(2, 3); // Alex - Kevin
	g.addEdge(3, 4); // Kevin - John
	g.addEdge(4, 0); // Larry - Bob

	g.printAdjacencyList();
	g.printAdjacencyMatrix();

	std::cout << "\nBreadth FS from Kevin:\n";
	g.breadthFS("Kevin");

	std::cout << "\n\nChecking cycle: ";
	for (int index : path)
		std::cout << names[index] << " ";
	std::cout << "\n";

	bool result = g.isCyclicalPath(path);
	std::cout << "\nCycle valid? " << (result ? "Yes" : "No") << std::endl;

	return 0;
}

int main()
{
	vector<string> names = {"Larry", "John", "Kevin", "Alex", "Bob"};
	vector<int> path = { 0, 1, 2, 3, 4, 0};
	Graph<string> g(names, true);
	g.printNodes();
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 1);
	g.printAdjacencyList();
	g.printAdjacencyMatrix();
	std::cout << std::endl << std::endl;
	g.breadthFS("Kevin");
	bool result = g.isCyclicalPath(path);
	return 0;
}
*/
