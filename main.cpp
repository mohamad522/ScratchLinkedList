#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "scriptFiles/LinkedList.hpp"

using namespace std;

TEST(LinkedListTest, LinkedListElt)
{
  LinkedList list1({1, 2, 3});
  list1[0] = 100;
  EXPECT_EQ(list1[0], 100);
  EXPECT_EQ(list1[1], 2);
}
