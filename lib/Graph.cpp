#include <stdio.h>
#include "Graph.h"
#include "minHeap.h"
#include "List.h"

namespace ece309 {

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
}
