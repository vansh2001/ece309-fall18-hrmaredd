#include <stdio.h>
#include <string.h>
#include "Graph.h"
#include "List.h"

class node_helper {
public:
  node_helper() {
    distance = INT_MAX;
    pred = -1;
  }
  int distance;
  int pred;
};

class MinHeap {
private:
  int *heapArray;    // this is the maxheap
  int heapArraySize; // size of the array
  int nextIndex;     // location of next free array entry
protected:
  void percolate_up(int);
  void percolate_down(int, int);

public:
  node_helper *nodesH = NULL;
  MinHeap(int size = 100, node_helper *j = NULL) : heapArraySize(size), nodesH(j) {
    heapArray = new int[size];
    for (int i = 0; i < size; i++)
      heapArray[i] = 0;
    nextIndex = 0;
  }

  void print() {
    for (int i = 0; i < nextIndex; i++) {
      printf("%d ", heapArray[i]);
    }
    printf("\n");
  }
  bool insert(int);
  bool remove(int &); // remove the max value
  bool empty() {return nextIndex == 0; }
};
