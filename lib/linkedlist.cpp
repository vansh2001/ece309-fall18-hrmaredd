#include <stdio.h>
#include<string>
#include <iostream>

using namespace std;
namespace ece309 {

class List{
public:

  class ListNode {
  private:
    string node_data;
    ListNode *next;
  public:
        ListNode(string  a)
    {
      node_data = a;
      next=NULL; // automatically serves as a list tail
    }
    ListNode* getNext()
    {
      return next;
    }
    void setNext(ListNode *n)
    {
      next = n;
    }
    string getItem()
    {
      return node_data;
    }

  };
  ListNode *head;
  ListNode *tail;

 void push_back(string a) {  //adds to the head
   ListNode *node = new ListNode(a);
   if (head==NULL) {
   // list is empty, so set head and
   // tail to be node
   head = node;
   tail = node;

   }else {
  // put new node at end of list
  tail->setNext(node);
  tail = node;
  }
 }

 string get(int n) { //Return a copy of the n-th item in the list.
   string copy;
   ListNode *tracker = head;
   for(int i = 1; i < n; i++) {
     tracker = tracker -> getNext();
   }
   copy = tracker -> getItem();
   // cout << copy << "\n";
   return copy;
 }

 int length() {
   ListNode *tracker = head;
   int counter = 0;
   while(tracker != NULL) {
     tracker = tracker -> getNext();
     counter++;
   }
   return counter;
 }

 string remove_front() { //Remove the head of the list and return a copy of the data that was removed.
   if (length() > 0) // if list is not empty
    {
       string copy = head->getItem(); // return copy
       ListNode *tmp = head->getNext();
       delete head; // delete the node
       head = tmp;  // update the head
   if (tmp==NULL) // removed last element
     tail = NULL;
  return copy;
   }
  return NULL; // nothing in list

 }
 // void print() {
 //   ListNode * temp = head;
 //   while (temp != NULL) {
 //     cout << temp -> getItem();
 //     temp = temp -> getNext();
 //   }
 // }

~List()
{
  ListNode* prev = head;
  while (prev != NULL) {
    ListNode* i = prev->getNext();
    delete prev;
    prev = i;
  }
}
};
}

 // int main (){
 //
 //   List l;
	// l.push_back("A");
	// l.push_back("d");
	// l.push_back("e");
 //  l.remove_front();
 //  l.get(1);
 //  l.print();
 //
 //
 // }
