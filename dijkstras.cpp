#include <queue>
#include <utility>
#include <map>

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
    //const int INF = 0x3f3f3f3f;                                 //Defines infinity

    std::map<Vertex, Vertex> previous;

    vector<Vertex> vertices = g_.getVertices();                 
    std::map<Vertex, bool> visited1;                            //Visited map 1 for creating priority queue
    std::map<Vertex, bool> visited2;                            //Visited map 2 for when going through priority queue later on
    for (int v = 0; v < vertices.size() - 1; ++v) {
        if (vertices[v] != a) {
            visited1[vertices[v]] = false;
            visited2[vertices[v]] = false;
        }
    }
    visited1[a] = true;

    //Creates priority queue
    std::queue<Vertex> tempQueue;                               //Initializes a setup queue to help initialize priority queue
    std::queue<Vertex> pq;
    tempQueue.push(a);
    while (tempQueue.empty() != true) {
        Vertex tempVertex = tempQueue.front();
        pq.push(tempVertex);
        tempQueue.pop();
        vector<Vertex> adj = g_.getAdjacent(tempVertex);
        for (int i = 0; i < adj.size() - 1; ++i) {
            if (visited1[adj[i]] == false) {
                visited1[adj[i]] == true;
                tempQueue.push(adj[i]);
            }
        }
    }

    for (int v = 0; v < )
    while (vectorpq.front().second != b) {
        Vertex temp = vectorpq.front().second;
        vectorpq.erase(vectorpq.begin());
        vector<Vertex> adjVertices = g_.getAdjacent(temp);
        for (int v = 0; v < adjVertices.size() - 1 && visited2[adjVertices[v]] != true; ++v) {
            Vertex destination = adjVertices[v].dest;
        }
    }
}