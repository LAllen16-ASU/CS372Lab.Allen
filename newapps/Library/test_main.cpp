#include "gtest/gtest.h"


TEST(SampleTest, BasicAssertions) {
	// Expect two strings to be equal.
	EXPECT_STREQ("hello", "hello");
	// Expect two integers to be equal.
	EXPECT_EQ(42, 42);
}

TEST(NextTest, BasicAssertions)
{
	EXPECT_EQ(1, 1);
}