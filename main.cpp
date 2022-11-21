#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "scriptFiles/LinkedList.hpp"

using namespace std;

TEST(LinkedListTest, LinkedListElt)
{
  LinkedList list1({1, 2, 3});
  list1.push_front(0);
  list1.push_back(4);
  EXPECT_EQ(list1[0], 0);
  EXPECT_EQ(list1[4], 4);
}
