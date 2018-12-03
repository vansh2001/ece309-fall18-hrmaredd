#include <stdio.h>
#include<string>
#include <iostream>
#include "IntegerSetArray.h"


using namespace std;

namespace ece309 {

IntegerSetArray::IntegerSetArray(int x):IntegerSet(x) {
  filled = 0;
  table = new int[x];
  for(int i = 0; i < x; i++){
    table[i] = 0;
  }
}

bool IntegerSetArray::insert(int data){
  // insert into table if there’s no collision
   if (filled == size) {
      return false;
   }
   table[filled++] = data;
   return true;
}

bool IntegerSetArray::search(int data) const {
  for(int i = 0; i < filled; i++){
    if(table[i] == data) {
      return true;
    }
  }
  return false;
}

void  IntegerSetArray::remove(int data) {
  for(int i = 0; i < filled; i++){
    if(table[i] == data) {
      for(int j = i; j < filled; j++ ) {
        table[i] = table[j+1];
      }
      filled--;
      i--;
    }
  }
  for(int k = filled; k < size; k++) {
    table[k] = 0;
  }
}
}
