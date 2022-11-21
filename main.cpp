#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "scriptFiles/LinkedList.hpp"

using namespace std;

TEST(LinkedListTest, LinkedListElt) {
  LinkedList list1({1, 2, 3});
  LinkedList list2({4, 5});
  LinkedList list3 = list1;
  EXPECT_EQ(list1 == list2, 0);
  EXPECT_EQ(list1 == list3, 1);
}
