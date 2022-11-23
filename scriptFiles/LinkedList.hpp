#include <iostream>
#include <vector>
#include <string>

using std::ostream;
using std::vector;
using std::string;


class LinkedList
{
public:
  LinkedList(const vector<short> & = {});
  LinkedList(const LinkedList &);
  LinkedList &operator=(const LinkedList &);
  ~LinkedList();
  short &operator[](int index);
  const short operator[](int index) const;
  void push_back(short);
  void push_front(short);
  int getSize() const;
  ostream &toOstream(ostream &out) const;
  bool operator==(const LinkedList &);
  LinkedList(const string&);
  

private:
  struct ListNode
  {
    ListNode(short val, ListNode *next = nullptr) : val(val), next(next) {}
    short val;
    ListNode *next;
  };
  ListNode *head;
  int size;
  friend void swap(LinkedList &, LinkedList &);
  friend ostream& operator<<(ostream& os, const LinkedList&);
};