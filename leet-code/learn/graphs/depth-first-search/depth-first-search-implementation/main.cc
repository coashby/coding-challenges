#include <string>

#include "depth-first-search.h"

int main(int argc, char* argv[]) {
  Graph<size_t> graph;
  graph.resize(6);
  graph[0] = {1, 2, 3};
  graph[1] = {0, 5};
  graph[2] = {0, 4};
  graph[3] = {0, 4};
  graph[4] = {3, 5};
  graph[5] = {1, 4};

  const size_t v = 0;
  const auto vertices = GraphSearch<size_t>::depthFirstSearch(graph, v);
  return EXIT_SUCCESS;
}