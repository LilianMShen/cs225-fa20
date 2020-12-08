#pragma once

#include <vector>

#include "BFS.h"
#include "graph.h"
#include "edge.h"

class Landmark {
  public: 
    Landmark(std::vector<std::vector<std::string>> data);
    std::vector<Edge> runLandmarkPath(Vertex start, Vertex end, Vertex landmark);

  private:
    Graph g_;
    std::vector<Edge> path_;
}