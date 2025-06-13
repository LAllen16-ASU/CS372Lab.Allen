#include "pch.h"
#include "../../apps/Assignment 03/List.hpp"

class ListTest : public ::testing::Test {
protected:
	List<int> myList;
};

//Test: List is empty.
//Precondition: a list exists and should be empty.
//Postcondition: the list is empty.
TEST_F(ListTest, empty)
{
	EXPECT_TRUE(myList.empty());
}

//Test: Add an element to the back of a list.
//Precondition: a list exists and should be empty.
//Postcondition: the list is no longer empty.
TEST_F(ListTest, push_back)
{
	myList.push_back(5);
	EXPECT_FALSE(myList.empty());
}

//Test: Add an element to the front of a list.
//Precondition: a list exists and should be empty.
//Postcondition: the list is no longer empty.
TEST_F(ListTest, push_front)
{
	myList.push_front(5);
	EXPECT_FALSE(myList.empty());
}

//Test: Remove an element from the front of a list.
//Precondition: a list exists that contains 2 or more elements.
//Postcondition: the front of the list is the remaining element.
TEST_F(ListTest, pop_front)
{
	myList.push_front(5);
	myList.push_front(9);
	EXPECT_FALSE(myList.empty());
	myList.pop_front();
	EXPECT_TRUE(myList.front() == 5);
}

//Test: Remove an element from the back of a list.
//Precondition: a list exists that contains 2 or more elements.
//Postcondition: the back of the list is the remaining element.
TEST_F(ListTest, pop_back)
{
	myList.push_back(5);
	myList.push_back(9);
	EXPECT_FALSE(myList.empty());
	myList.pop_back();
	EXPECT_TRUE(myList.back() == 5);
}
