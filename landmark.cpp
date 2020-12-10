#include "landmark.h"

Landmark::Landmark(std::vector<std::vector<std::string>> data) : g_(false, false) {
  for (size_t i = 0; i < data.size() - 1; ++i) {
    if (g_.vertexExists(data[i][0]) == false) {
      g_.insertVertex(data[i][0]);
    }
    if (g_.vertexExists(data[i][1]) == false) {
      g_.insertVertex(data[i][1]);
    }
    if (g_.edgeExists(data[i][0], data[i][1]) == false) {
      g_.insertEdge(data[i][0], data[i][1]);
      g_.setEdgeWeight(data[i][0], data[i][1], 0);
    }
  }
}

std::vector<Edge> Landmark::runLandmarkPath(Vertex start, Vertex end, Vertex landmark) {
  std::queue<Vertex> queue;
  std::map<Vertex, Vertex> visited; // <vertex, predecessor>

  std::vector<Edge> result;
  std::vector<Edge> startPath; // Represents path from start to landmark
  std::vector<Edge> endPath; // Represents path from landmark to end

  // BFS traversal to find path from start to end point
  queue.push(landmark);
  visited[landmark] = landmark;

  bool foundEndpoint = false;
  bool foundStartpoint = false;
  while (!queue.empty() && (!foundEndpoint || !foundStartpoint)) {
    Vertex current = queue.front();
    queue.pop();

    // Get all adjacent vertices, add to queue if not visited and mark predecessor in map
    std::vector<Vertex> adjacent = g_.getAdjacent(current);
    for (Vertex v : adjacent) {
      if (visited.count(v) < 1) {
        queue.push(v);
        visited[v] = current; // set predecessor
      }

      if (v == end) { // Check if vertex is the endpoint
        endPath = getEdgePathFromMap(visited, v);
        foundEndpoint = true;
      }

      if (v == start) { // Check if vertex is the startpoint
        startPath = getEdgePathFromMap(visited, v);
        foundStartpoint = true;
      }
    }
  }

  // Add start path edges to result
  for (Edge e : startPath) {
    result.push_back(e);
  }

  // Add ending path edges to result
  for (int i = endPath.size() - 1; i >= 0; i--) {
    result.push_back(endPath[i]);
  }

  return result;
}

std::vector<Edge> Landmark::getEdgePathFromMap(std::map<Vertex, Vertex> visited, Vertex current) {
  std::vector<Edge> result;

  Vertex curr = current;
  while (visited[curr] != curr) { // For a vertex without a predecessor (vertex at start of traversal), stores itself as predecessor
    result.push_back(Edge(visited[curr], curr)); // Add edge from current Vertex and predecessor Vertex
    curr = visited[curr]; // Set current edge to predecessor vertex
  }

  // With current implementation, path is returned in backward order
  return result;
}