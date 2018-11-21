#include <stdio.h>
#include "Graph.h"
#include "minHeap.h"
#include "List.h"


// SparseGraph::SparseGraph(int n) : Graph(n) { nodes = new Node[numNodes]; }
//
// void SparseGraph::addEdge(int v1, int v2) {
//   nodes[v1].edge.append(v2);
//   nodes[v2].edge.append(v1);
// }
//
// bool SparseGraph::isAdjacent(int v1, int v2) const {
//   List::iterator it = nodes[v1].edge.begin();
//   while (!it.end()) {
//     if (it.getItem() == v2) {
//       return true;
//     }
//     it.increment();
//   }
//   return false;
// }
//
// DenseGraph::DenseGraph(int n) : Graph(n) {
//   edges = new bool[numNodes * numNodes];
//   for (int i = 0; i < numNodes * numNodes; i++)
//     edges[i] = false;
// }
// void DenseGraph::addEdge(int v1, int v2) {
//   edges[v1 * numNodes + v2] = true;
//   edges[v2 * numNodes + v1] = true;
// }
//
// bool DenseGraph::isAdjacent(int v1, int v2) const {
//   return edges[v1 * numNodes + v2];
// }
//
// bool doesPathExist(Graph &g, int *path, int length) {
//   for (int i = 0; i < length - 1; i++) {
//     if (!g.isAdjacent(path[i], path[i + 1]))
//       return false;
//   }
//   return true;
// }
//
// void visit(int node) { printf("%d ", node); }

node_helper *ShortestPath(Graph &g, int startV) {

  int numNodes = g.getNumNodes();
  node_helper *nodesH = new node_helper[numNodes];

  nodesH[startV].distance = 0;
  MinHeap unvisitedHeap(g.getNumNodes(), nodesH);

  for (int i = 0; i < numNodes; i++)
    unvisitedHeap.insert(i);
    bool ff = false;

  while (!unvisitedHeap.empty()) {
    int currentV = 0;
    if(ff) unvisitedHeap.remove(currentV);
      ff = true;
      int min_distance = nodesH[currentV].distance;

    List adjList = g.getAdjacencyList(currentV);
    for (List::iterator lit = adjList.begin(); !lit.end(); lit.increment()) {
      int toNode = lit.getItem();
      if (g.getWeight(currentV, toNode) + min_distance <
          nodesH[toNode].distance) {
        nodesH[toNode].distance = g.getWeight(currentV, toNode) + min_distance;
        nodesH[toNode].pred = currentV;
      }
    }
  }
  return nodesH;
}

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
