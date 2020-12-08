#include "landmark.h"

Landmark::Landmark(std::vector<std::vector<std::string>> data) : g_(false, false) {
  for (int i = 0; i < data.size() - 1; ++i) {
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
  std::vector<Edge> result;
  return result;
}

std::vector<Edge> Landmark::findBFSPathToVertex(Vertex start, Vertex end) {
  std::queue<Vertex> queue;
  std::map<Vertex, Vertex> visited; // current vertex, predecessor
  std::vector<Edge> result;

  // BFS traversal to find path from start to end point
  queue.push(start);
  visited[start] = start;

  bool foundEndpoint = false;
  while (!queue.empty() && !foundEndpoint) {
    Vertex current = queue.front();
    queue.pop();

    // Get all adjacent vertices, add to queue if not visited and mark predecessor in map
    std::vector<Vertex> adjacent = g_.getAdjacent(current);
    for (Vertex v : adjacent) {
      if (v == end) { // Check if vertex is the landmark, if so break
        result = getEdgePathFromMap(visited);
        foundEndpoint = true;
        break;
      }

      if (!visited.contains(v)) {
        queue.push(v);
        visited[v] = current; // set predecessor
      }
    }
  }

  return result;
}

std::vector<Edge> Landmark::getEdgePathFromMap(std::map<Vertex, Vertex> visited) {

}