#include <iostream>
#include <vector>
#include <memory>
using std::ostream;
using std::vector;
using std::shared_ptr;

class LinkedList
{
public:
  LinkedList(const vector<short> & = {});
  LinkedList(const LinkedList &);
  LinkedList &operator=(const LinkedList &);
  // ~LinkedList();
  short &operator[](int index);
  const short operator[](int index) const;
  void push_back(short);
  void push_front(short);
  int getSize() const;
  ostream &toOstream(ostream &out) const;
  bool operator==(const LinkedList &);
  

private:
  struct ListNode
  {
    ListNode(short val, shared_ptr<ListNode> next = nullptr) : val(val), next(next) {}
    short val;
    shared_ptr<ListNode> next;
  };
  shared_ptr<ListNode> head;
  int size;
  friend void swap(LinkedList &, LinkedList &);
  friend ostream& operator<<(ostream& os, const LinkedList&);
};