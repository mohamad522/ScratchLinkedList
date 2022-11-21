#include <iostream>
#include <vector>
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
LinkedList &LinkedList::operator=(const LinkedList &l)
{
  head->val = l.head->val;
  ListNode *temp = head;
  ListNode *ltemp = l.head;
  while (ltemp->next && temp->next)
  {
    temp->next->val = ltemp->next->val;
    temp = temp->next;
    ltemp = ltemp->next;
  }
  if(size < l.size) {
    for (int i(0); i < l.size - size; ++i) {
      temp->next = new ListNode(ltemp->next->val);
      temp = temp->next;
      ltemp = ltemp->next;
    }
    
  }
  if (size > l.size)
  {
    temp = temp->next;
    ListNode *a;
    for (int i(0); i < size - l.size; ++i)
    {
      a = temp->next;
      delete temp;
      temp = nullptr;
      temp = a;
  }
  }
  size = l.size;

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