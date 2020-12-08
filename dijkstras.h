#pragma once

#include <vector>
#include <algorithm>
#include <string>

#include "graph.h"
#include "edge.h"

class Dijkstras {
    public:
        //Constructor that creates a graph from the dataset of connected users
        Dijkstras(std::vector<std::vector<std::string>> data);

        //Returns a vector of edges that represents the shortest path from Vertex a to b
        void Dijkstras_Helper(Vertex a, Vertex b);

        std::vector<Edge> Dijkstras(std::vector<std::vector<std::string>> data, Vertex a, Vertex b);
    private:
        Graph g_;
}