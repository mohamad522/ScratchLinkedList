#include <iostream>
#include <gtest/gtest.h>
#include "scriptFiles/LinkedList.hpp"
#include <fstream>

using namespace std;

TEST(LinkedListTest, LinkedListElt) {
  LinkedList liste1("D:/1ere/OOP/projects/LinkedList/file_1.txt"); //il vaut mieux donner le chemin d'acces complet au fichier
  EXPECT_EQ(liste1[0], 10);
}

//D:/1ere/OOP/projects/LinkedList/file_1.txt