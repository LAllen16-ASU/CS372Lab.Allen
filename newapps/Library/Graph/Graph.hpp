#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>

using std::map;
using std::set;
using std::vector;
using std::queue;

template <typename T>
class Graph
{
private:
	map<T, vector<T>> adjacencyList;
	vector<vector<int>> adjacencyMatrix;
	vector<T> nodes;
	bool isDirected;
	
public:
	Graph(vector<T> data, bool directed)
	{
		nodes = data;
		isDirected = directed;
		adjacencyMatrix = vector<vector<int>>(nodes.size(), vector<int>(nodes.size(), 0));
	}

	void printNodes();
	void addEdge(int source, int destination);
	void printAdjacencyList();
	void printAdjacencyMatrix();
	void breadthFS(T firstNode);
	bool isCyclicalPath(vector<int> path);
	vector<T> visit(T key);
};


template<typename T>
void Graph<T>::addEdge(int source, int destination)
{
	// add the destination index to the source's edge vector
	// add the destination index to the source index of the matrix
	if (isDirected)
	{
		adjacencyList[nodes[source]].push_back(nodes[destination]);
		adjacencyMatrix[source][destination] = 1;
	}
	else
	{
		adjacencyList[nodes[source]].push_back(nodes[destination]);
		adjacencyList[nodes[destination]].push_back(nodes[source]);
		adjacencyMatrix[source][destination] = 1;
		adjacencyMatrix[destination][source] = 1;
	}
}

template <typename T>
void Graph<T>::breadthFS(T firstNode)
{
	if (adjacencyList.find(firstNode) == adjacencyList.end())
	{
		std::cout << "Not found." << std::endl;
		return;
	}
	queue<T> visiting;
	set<T> visited;
	
	visiting.push(firstNode);
	visited.insert(firstNode);

	while (!visiting.empty())
	{
		T current = visiting.front();
		visiting.pop();
		std::cout << current << " "; // process node

		for (const T& neighbor : adjacencyList[current])
		{
			if (visited.find(neighbor) == visited.end())
			{
				visiting.push(neighbor);
				visited.insert(neighbor);
			}
		}
	}
	std::cout << std::endl;
}

template<typename T>
vector<T> Graph<T>::visit(T key)
{
	return adjacencyList[key];
}

template<typename T>
bool Graph<T>::isCyclicalPath(vector<int> path)
{
	if (path.size() < 3)
	{
		std::cout << "Can't be cyclical if less than 3 nodes." << std::endl;
		return false;
	}
	if (path.front() != path.back())
	{
		std::cout << "Can't be cyclical if beginning and end aren't equal." << std::endl;
		return false;
	}
	set<int> visited;
	for (int i = 0; i < path.size() - 1; ++i)
	{
		int current = path[i];
		int next = path[i + 1];

		if (visited.count(current))
		{
			std::cout << "Path contains a sub-cycle." << std::endl;
			return false;
		}
		visited.insert(current);

		vector<T> neighbors = visit(nodes[current]);
		bool connected = false;

		for (const T& neighbor : neighbors)
		{
			if (neighbor == nodes[next])
			{
				connected = true;
				break;
			}
		}
		if (!connected)
		{
			std::cout << "The path is not cyclical." << std::endl;
			return false;
		}
	}
	std::cout << "The path is cyclical." << std::endl;
	return true;
}

template <typename T>
void Graph<T>::printNodes()
{
	for (int i = 0; i < nodes.size(); ++i)
	{
		std::cout << nodes[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void Graph<T>::printAdjacencyList()
{
	for (int i = 0; i < nodes.size(); ++i)
	{
		std::cout << nodes[i] << ": ";
		for (int j = 0; j < adjacencyList[nodes[i]].size(); ++j)
		{
			std::cout << adjacencyList[nodes[i]][j] << " ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
void Graph<T>::printAdjacencyMatrix()
{
	for (int i = 0; i < adjacencyMatrix.size(); ++i)
	{
		for (int j = 0; j < adjacencyMatrix.size(); ++j)
		{
			std::cout << adjacencyMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}