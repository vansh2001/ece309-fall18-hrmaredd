#include <stdio.h>
#include <string>
#include <iostream>
#include "PList.h"

int main() {

  PList new_list;

  Object* num = new Integer(4);
  Object* dollars = new Doubles(10.2);
  Object* Letters = new Strings((char *)"BOBA");
  Object* dollars_2 = new Doubles(1.49);
  Object* num_2 = new Integer(12);
  Object* Letters_2 = new Strings((char *)"Bubble_Tea");


    new_list.append(num);
    new_list.append(dollars);
    new_list.append(Letters);
    new_list.append(dollars_2);
    new_list.append(num_2);
    new_list.append(Letters_2);

    PList::iterator it = new_list.begin();
    while (!it.end()) {
      it.node->getItem()->print();
      it.increment();
     }
     //remove 4th object and reprint the list
     it = new_list.begin();
     //reset iterator it.increment();
     it.increment();
     new_list.removeAfter(it); //remove the 4th item
     it = new_list.begin(); //reset iterator
     printf("reprint the list\n");
     while(!it.end()) {
       it.node->getItem()->print();
       it.increment();
    }

  return 0;
}
