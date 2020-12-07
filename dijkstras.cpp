#include <queue>
#include <utility>

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

void Dijkstras::runDijkstras(Vertex a, Vertex b) {
    const int INF = 0x3f3f3f3f;                             //Defines infinity
    vector<Vertex> vertices = g_.getVertices();
    std::priority_queue<pair<int, Vertex>> pq;
    pq.push(make_pair(0, vertices[0]));
    for (int v = 0; v < vertices.size() - 1; ++v) {         //Sort by vertex distance with priority queue
        pq.push(make_pair(INF, vertices[v]));
    }
    vector<pair<int, Vertex>> vectorpq;

    while (!pq.empty()) {
        Vertex temp = vectorpq.front().second;
        vectorpq.erase(vectorpq.begin());
        vector<Edge> adjEdges = g_.getAdjacent(temp);
        for (int e = 0; e < adjEdges.size() - 1; ++e) {
            Vertex destination = adjEdges[e].dest;
        }
    }
}