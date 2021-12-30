#include "gtest/gtest.h"
#include "RedStar/MyHeader.h"
#include <iostream>

TEST(MyTestSuite, ExampleTest)
{
	ASSERT_EQ(add(4, 2), 6);
}