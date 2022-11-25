#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(const vector<short> &v)
    : size(v.size())
{
  if (!size)
    return;
  head = make_shared <ListNode> (ListNode(v[0]));
  shared_ptr<ListNode> temp = head;
  for (int i(1); i < size; ++i)
  {
    temp->next = make_shared <ListNode> (ListNode(v[i]));
    temp = temp->next;
  }
}
LinkedList::LinkedList(const LinkedList &l)
    : size(l.size)
{
  if (!size)
    return;
  head = make_shared <ListNode> (ListNode(l.head->val));
  shared_ptr<ListNode> temp = head;
  shared_ptr<ListNode> ltemp = l.head;
  while (ltemp->next)
  {
    temp->next = make_shared <ListNode> (ListNode(ltemp->next->val));
    temp = temp->next;
    ltemp = ltemp->next;
  }
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
  head = make_shared <ListNode> (num);
  shared_ptr<ListNode> temp = head;
  size = 1;
  while (!indata.eof())
  {
    indata >> num;
    temp->next = make_shared <ListNode> (num);
    temp = temp->next;
    size++;
  }
  indata.close();
}

void swap(LinkedList &l1, LinkedList &l2) {
  shared_ptr<LinkedList::ListNode> temp = l1.head;
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
  shared_ptr<LinkedList::ListNode> temp = head;

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
  shared_ptr<ListNode> temp = head;
  shared_ptr<ListNode> ltemp = l.head;
  
  for(int i(0); i < size; ++i) {
    if(temp->val != ltemp->val) return false;
    temp = temp->next;
    ltemp = ltemp->next;
  }
  return true;
}
short &LinkedList::operator[](int index)
{
  shared_ptr<ListNode> temp = head;
  for (int i(0); i < index; ++i)
  {
    temp = temp->next;
  }
  return temp->val;
}

const short LinkedList::operator[](int index) const {
  shared_ptr<ListNode> temp = head;
  for(int i(0); i < index; ++i) {
    temp = temp->next;
  }
  short val = temp->val;
  return val;
}
void LinkedList::push_back(short x) {
  shared_ptr<ListNode> temp = head;
  for(int i(0); i < size - 1; ++i) {
    temp = temp->next;
  }
  temp->next = make_shared<ListNode> (ListNode(x));
  size++;
}
void LinkedList::push_front(short x) {
  head = make_shared<ListNode> (ListNode(x, head));
  size++;
}