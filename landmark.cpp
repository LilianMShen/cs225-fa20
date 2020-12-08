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

void Landmark::runLandmarkPath(Vertex start, Vertex end, Vertex landmark) {
  
}