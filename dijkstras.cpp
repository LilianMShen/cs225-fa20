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
            g_.setEdgeWeight(data[i][0], data[i][1], 0);
        }
    }
}

 /*
 Initialize distances
 Initialize previous (initialize a map that maps current node -> its previous node)
 initialize priority_queue
 initialize visited

 while the top of pq is not destination:
    get current_node from pq
    for neighbor in current_node's neighbors and not in visited:
        if update its neighbor's distances:
            previous[neighbor] = current_node
    save current_node into visited

extract path from previous
return path and distance
 */
void Dijkstras::runDijkstras(Vertex a, Vertex b) {
    
}