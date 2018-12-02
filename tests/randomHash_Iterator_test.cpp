#include <stdio.h>
#include <string>
#include <iostream>
#include "randomHash_Iterator.h"


int main() {
    IntegerSetHT set(100);
    set.insert(5);
    set.insert(99);
    set.insert(0);

   IntegerSetHT::iterator sit = set.begin();
    while(!sit.end())
    {
      printf("%d", sit.getInt());
      sit.increment();
    }
  printf("\n");
  return 0;
}
