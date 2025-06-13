#include "pch.h"
#include "../../apps/Assignment 03/CircularList.hpp"

class CListTest : public ::testing::Test {
protected:
	CircularList<int> myCList;
};

//Test: The Circular List is empty.
//Precondition: a circular list exists and is empty.
//Postcondition: the circular list is empty.
TEST_F(CListTest, cEmpty)
{
	EXPECT_TRUE(myCList.empty());
}

//Test: The push_back function is working.
//Precondition: two elements are pushed onto the circular list back.
//Postcondition: the back() of the circular list is the same data as the 2nd push_back() call
TEST_F(CListTest, push_back)
{
	myCList.push_back(5);
	myCList.push_back(9);
	EXPECT_TRUE(myCList.back() == 9);
}

//Test: The push_front function is working.
//Precondition: two elements are pushed onto the circular list back.
//Postcondition: the front() of the circular list is the same data as the 2nd push_front() call
TEST_F(CListTest, push_front)
{
	myCList.push_front(5);
	myCList.push_front(9);
	EXPECT_TRUE(myCList.front() == 9);
}