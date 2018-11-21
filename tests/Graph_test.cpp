#include <stdio.h>
#include "Graph.h"
#include "minHeap.h"
#include "List.h"



int main(){
   printf("graph worked\n");
   MinHeap heap;
   heap.insert(45);

   heap.insert(100);

  heap.insert(83);
  heap.insert(15);

  heap.insert(5);
  heap.insert(50);
  heap.insert(82);

  printf("printing heap\n");
  heap.print();
  printf("Minheap succesfull\n");

  return 0;
}
