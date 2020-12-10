#pragma once

#include <vector>

#include "BFS.h"
#include "graph.h"
#include "edge.h"

class Landmark {
  public: 
    // Constructor to initialize graph to run landmark algorithm
    Landmark(std::vector<std::vector<std::string>> data);

    // Runs the landmark path algorithm
    std::vector<Edge> runLandmarkPath(Vertex start, Vertex end, Vertex landmark);

    //Getter for graph
    Graph getGraph();
  private:
    Graph g_;

    // Helper function for runLandmarkPath to get a vector of edges given a map of previous visited vertices
    std::vector<Edge> getEdgePathFromMap(std::map<Vertex, Vertex> visited, Vertex current);
};