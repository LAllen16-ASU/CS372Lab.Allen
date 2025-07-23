// FinalExam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.hpp"
#include <list>
#include "Table.hpp"
using namespace std;

//function referencing the root of a Tree passed by reference, returning an integer value that is the number of nodes in the Tree
template <typename T>
int numNodes(Tree<T> tree);
//function counting the number of internal nodes with a Tree passed by reference, returning an integer value.
template <typename T>
int numInternalNodes(Tree<T> tree);
//function counting the path length and storing it in an integer
template<typename T>
void pathLength(Tree<T> tree, int& sum);

template<typename T>
void partitionList(T splittingVal, list<T>* inputList, list<T>* lesserList, list<T>* greaterList);

template<typename T>
list<T>* quickSort(list<T>* myList);
template<typename T>
void printList(list<T>* l);

int main()
{
    // =========== Question 1 ===========
    std::cout << "=========== Begin Question 1 ===========" << std::endl << std::endl;
    int lengthSum = 0;
    Tree<int> myTree;
    myTree = myTree.insert(5);
    myTree = myTree.insert(4);
    myTree = myTree.insert(9);
    myTree = myTree.insert(7);
    std::cout << "Number of Nodes: " << numNodes(myTree) << std::endl;
    pathLength(myTree, lengthSum);
    std::cout << "External Path Length: " << lengthSum << std::endl;
    std::cout << "Number of Internal Nodes: " << numInternalNodes(myTree) << std::endl;
    std::cout  << std::endl << "=========== End Question 1 ===========" << std::endl << std::endl;

    // =========== Question 2 ===========
    std::cout << "=========== Begin Question 2 ===========" << std::endl << std::endl;

    list<int>* myList = new list<int>();
    myList->push_back(5);
    myList->push_back(9);
    myList = quickSort(myList);
    //printList(myList);
    delete myList;

    std::cout << std::endl << "=========== End Question 2 ===========" << std::endl << std::endl;
    // =========== Question 3 ===========
    std::cout << "=========== Begin Question 3 ===========" << std::endl << std::endl;

    std::cout << "The answer to question 3 can be found in the Table.hpp file included.";

    std::cout << std::endl << "=========== End Question 3 ===========" << std::endl << std::endl;
}

// Question 1a
template <typename T>
int numNodes(Tree<T> tree)
{
    // traverse the Tree from the root if the root is not the only node
    if (tree.isEmpty())
    {
        return 0;
    }
    else
    {
        // repeat the operation adding 1 for each node found.
        return 1 + numNodes(tree.left()) + numNodes(tree.right());
    }
}

// Question 1b
template<typename T>
int numInternalNodes(Tree<T> tree)
{
    if (tree.isEmpty())
    {
        return 0;
    }
    // if the children are empty don't add to the result.
    if (tree.left().isEmpty() && tree.right().isEmpty())
    {
        return 0;
    }
    else
    {
        return 1 + numInternalNodes(tree.left()) + numInternalNodes(tree.right());
    }
}

// Question 1c
template<typename T>
void pathLength(Tree<T> tree, int& sum)
{
    if (tree.isEmpty())
    {
        sum += 0;
    }
    else
    {
        // add one to sum and recursively call on the children
        sum += 1;
        pathLength(tree.left(), sum);
        pathLength(tree.right(), sum);
    }
    
}

// Question 2a
template<typename T>
void partitionList(T splittingVal, list<T>* inputList, list<T>* lesserList, list<T>* greaterList)
{
    for (int i = 0; i < inputList.size(); ++i)
    {
        auto l_front = inputList.begin();
        advance(l_front, i);
        if (*l_front < splittingVal)
        {
            lesserList->push_back(*l_front);
        }
        if (*l_front > splittingVal)
        {
            greaterList->push_back(*l_front);
        }
    }
}

template <typename T>
void printList(list<T>* l)
{
    std::cout << "[";
    auto f = l.begin();
    while (f != l.end())
    {
        std::cout << " " << *f;
        advance(f, 1);
    }
    std::cout << " ]" << std::endl;
}

template <typename T>
list<T>* quickSort(list<T>* myList)
{
    auto it = myList->begin();
    T pivot = *it;
    list<T>* lesserList = new list<T>();
    list<T>* greaterList = new list<T>();

    partitionList(pivot, myList, lesserList, greaterList);
    list<T>* lesserSorted = quickSort(lesserList);
    list<T>* greaterSorted = quickSort(greaterList);

    list<T>* result = new list<T>();
    
    for (int i = 0; i < lesserList->size(); ++i)
    {
        auto l_front = lesserList->begin();
        advance(l_front, i);
        result->push_back(*l_front);
    }
    for (int j = 0; j < greaterList->size(); ++j)
    {
        auto g_front = greaterList->begin();
        advance(g_front, j);
        result->push_back(*g_front);
    }

    delete lesserSorted;
    delete greaterSorted;

    return result;
}