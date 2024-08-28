#include <forward_list>
#include <unordered_set>
#include <vector>

template <typename T>
using Graph = std::vector<std::forward_list<T>>;

template <typename T>
class GraphSearch {
 public:
  static std::vector<size_t> depthFirstSearch(const Graph<T>& graph,
                                              const size_t v) {
    std::vector<size_t> visited_vertices;
    std::unordered_set<size_t> visited;
    depthFirstSearch(graph, v, visited_vertices, visited);
    return visited_vertices;
  }

 private:
  static void depthFirstSearch(const Graph<T>& graph, const size_t v,
                               std::vector<size_t>& visited_vertices,
                               std::unordered_set<size_t>& visited) {
    // If the node has been previously visited, ignore.
    if (visited.count(v) > 0) {
      return;
    } else {
      // Visit the node if it hasn't already been visited.
      visited.insert(v);
      visited_vertices.push_back(v);
      // Get the adjacency list for vertex v.
      const auto& v_adj_list = graph[v];
      for (const auto& next_v : v_adj_list) {
        depthFirstSearch(graph, next_v, visited_vertices, visited);
      }
    }
  }
};