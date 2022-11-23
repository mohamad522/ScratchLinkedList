#include <iostream>
#include <vector>
#include <fstream>
#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(const vector<short> &v)
    : size(v.size())
{
  if (!size)
    return;
  head = new ListNode(v[0]);
  ListNode *temp = head;
  for (int i(1); i < size; ++i)
  {
    temp->next = new ListNode(v[i]);
    temp = temp->next;
  }
  temp = nullptr;
  delete temp;
}
LinkedList::LinkedList(const LinkedList &l)
    : size(l.size)
{
  if (!size)
    return;
  head = new ListNode(l.head->val);
  ListNode *temp = head;
  ListNode *ltemp = l.head;
  while (ltemp->next)
  {
    temp->next = new ListNode(ltemp->next->val);
    temp = temp->next;
    ltemp = ltemp->next;
  }
  temp = nullptr;
  delete temp;
  ltemp = nullptr;
  delete ltemp;
}
LinkedList::LinkedList(const string &file)
{

  ifstream indata;
  int num;           // variable for input value
  indata.open(file); // opens the file
  if (!indata)
  {
    cerr << "Error: file could not be opened" << endl;
    exit(1);
  }
  indata >> num;
  head = new ListNode(num);
  ListNode *temp = head;
  size = 1;
  while (!indata.eof())
  {
    indata >> num;
    temp->next = new ListNode(num);
    temp = temp->next;
    size++;
  }
  temp = nullptr;
  delete temp;
  indata.close();
}

LinkedList::~LinkedList()
{
  ListNode *temp = head;
  ListNode *a;
  for (int i(0); i < size; ++i)
  {
    a = temp->next;
    delete temp;
    temp = a;
  }
}
void swap(LinkedList &l1, LinkedList &l2) {
  LinkedList::ListNode *temp = l1.head;
  l1.head = l2.head;
  l2.head = temp;
  int tempS = l1.size;
  l1.size = l2.size;
  l2.size = tempS;
}
LinkedList &LinkedList::operator=(const LinkedList &l)
{
  LinkedList L(l);
  swap(*this, L);
  return *this;
}
ostream & LinkedList::toOstream(ostream &out) const {
  if(!size) {
    out << "List empty\n";
    return out;
  }
  LinkedList::ListNode *temp = head;

  for (int i(0); i < size; ++i)
  {
    out << temp->val << " ";
    temp = temp->next;
  }
  return out;
}
ostream &operator<<(ostream &os, const LinkedList &l)
{
  return l.toOstream(os);
}
bool LinkedList::operator==(const LinkedList &l) {
  if(size != l.size) return false;
  ListNode *temp = head;
  ListNode *ltemp = l.head;
  
  for(int i(0); i < size; ++i) {
    if(temp->val != ltemp->val) return false;
    temp = temp->next;
    ltemp = ltemp->next;
  }
  return true;
}
short &LinkedList::operator[](int index)
{
  ListNode *temp = head;
  for (int i(0); i < index; ++i)
  {
    temp = temp->next;
  }
  return temp->val;
}

const short LinkedList::operator[](int index) const {
  ListNode *temp = head;
  for(int i(0); i < index; ++i) {
    temp = temp->next;
  }
  short val = temp->val;
  delete temp;
  temp = nullptr;
  return val;
}
void LinkedList::push_back(short x) {
  ListNode *temp = head;
  for(int i(0); i < size - 1; ++i) {
    temp = temp->next;
  }
  temp->next = new ListNode(x);
  size++;
}
void LinkedList::push_front(short x) {
  head = new ListNode(x, head);
  size++;
}
