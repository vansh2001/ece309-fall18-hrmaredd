#include <stdio.h>
#include <string>
#include <iostream>
#include "PList.h"

int main() {

  PList new_list; //list Object created

  //------------------------ assigned variables names
  Object* num = new Integer(4);
  Object* dollars = new Doubles(10.2);
  Object* Letters = new Strings((char *)"BOBA");
  Object* dollars_2 = new Doubles(1.49);
  Object* num_2 = new Integer(12);
  Object* Letters_3 = new Strings((char *)"Jasmine");
  Object* Letters_4 = new Strings((char *)"Green");
  Object* Letters_5 = new Strings((char *)"Pink");

  //------------------------ Appended a list to inster-----
  new_list.append(num);
  new_list.append(dollars);
  new_list.append(Letters);
  new_list.append(dollars_2);
  new_list.append(num_2);
  new_list.append(Letters_3);
  new_list.append(Letters_4);
  new_list.append(Letters_5);
// inistilaized iterator to being
  PList::iterator it = new_list.begin();

//Print all in the list
  while (!it.end()) {
    it.node->getItem()->print();
    it.increment();
   }

   printf("---------------\n");
   it = new_list.begin();
   it.increment();
   new_list.removeAfter(it);
   it = new_list.begin();


   while(!it.end()) {
     it.node->getItem()->print();
     it.increment();
  }
  printf("---------------\n");
  it = new_list.begin();
  it.increment();
  new_list.removeAfter(it);
  it = new_list.begin();

  while(!it.end()) {
    it.node->getItem()->print();
    it.increment();
 }

  return 0;
}
