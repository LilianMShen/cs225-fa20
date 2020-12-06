//#include <sstream>
//#include <map>

#include "dijkstras.h"
#include "graph.h"

Dijkstras::Dijkstras(vector<vector<string>> data) : g_(false, false) {
    for (int i = 0; i < data.size() - 1; ++i) {
        if (g_.vertexExists(data[i][0]) == false) {
            g_.insertVertex(data[i][0]);
        }
        if (g_.vertexExists(data[i][1]) == false) {
            g_.insertVertex(data[i][1]);
        }
        if (g_.edgeExists(data[i][0], data[i][1]) == false) {
            g_.insertEdge(data[i][0], data[i][1]);
        }
    }
}

std::vector<Edge> Dijkstras::runDijkstras(Vertex a, Vertex b) {
    
}