#include <stdio.h>
#include <string>
#include <iostream>
#include "PList.h"

//using namespace std;
namespace ece309 {

PList::iterator PList::begin(){
  return iterator(head);
}

void PList::append(Object *a){
  ListNode *node = new ListNode(a);
  if (head==NULL) {
     // list is empty, so set head and
     // tail to be node
     head = node;
     tail = node;
  } else {
    // put new node at end of list
    tail->setNext(node);
    tail = node;
  }
}


void PList::removeAfter(PList::iterator it) // pseudocode in zyBook 2.4
{
     if (it.node==NULL) // special case to remove head, it’s not after any node
     {
          ListNode *remove = head;               // will remove the head
          head = head->getNext();      // advance head
          if (head==NULL) tail = NULL; // if head is NULL now, list is empty
  	   delete remove;               // delete removed node
      }
      else // normal case, if not the head, then simply disconnect the node
      {
          ListNode *tmp = it.node;
  	   ListNode *remove = tmp->getNext(); // next node to be removed
     tmp->setNext(remove->getNext());   // point around node to be removed
     if (tail==remove) tail = tmp;      // if removing tail, update tail
     delete remove; // delete node      // delete the removed node
  }
}

void PList::insertAfter(iterator it, Object *item){
  if (it.node==NULL) { // special case to insert at the head
          // point new node at current head of list
          ListNode *node = new ListNode(item,head);
          if (head==NULL) { // if head was NULL, tail was also NULL
             tail = node;   // new node is now the tail
             head = node;   // new node is now the head
          } else {
             head = node;   // update head to new node
          }
    }
    else // insert after it
    {
          ListNode *node = new ListNode(item,it.node->getNext());
          it.node->setNext(node);
          if (tail==it.node) tail = node;
  }
}
}
