#include <queue>
#include <utility>
#include <map>
#include <functional>

#include "dijkstras.h"
#include "graph.h"

Dijkstras::Dijkstras(vector<vector<string>> data) : g_(false, false) {
    for (int i = 0; i < data.size() - 1; ++i) {
        //Inserts all vertices
        if (g_.vertexExists(data[i][0]) == false) {
            g_.insertVertex(data[i][0]);
        }
        if (g_.vertexExists(data[i][1]) == false) {
            g_.insertVertex(data[i][1]);
        }
        
        /*
        Inserts all edges. All edge weights are set to 0 because the data 
        is unweighted. No section available for weights. The dataset (csv)
        is parsed through with the fileio code, which returns a vector,
        which contains vectors each containing a source and destination
        node, which represent an edge.
        */
        if (g_.edgeExists(data[i][0], data[i][1]) == false) {
            g_.insertEdge(data[i][0], data[i][1]);
            g_.setEdgeWeight(data[i][0], data[i][1], 0);
        }
    }
}

void Dijkstras::Dijkstras_Helper(Vertex a, Vertex b) {
    //Definitions
    const int INF = 0x3f3f3f3f;
    typedef int distance;
    typedef pair<distance, Vertex> vDistPair;

    //Initializes map of distance for each vertex, all distances set to infinity at start
    vector<Vertex> allVertices = g_.getVertices();
    std::map<Vertex, distance> dist;
    for (int v = 0; v < allVertices.size() - 1; ++v) {
        dist[allVertices[v]] = INF;
    }

    //Initialize priority queue (min-heap), with source vertex's distance = 0
    std::priority_queue<vDistPair, vector<vDistPair>, std::greater<vDistPair>> pq;
    pq.push(make_pair(0, a));

    //Initialize visited vertices map
    std::map<Vertex, bool> visited;

    //Loops until it reaches destination vertex
    while (pq.top().second != b) {
        Vertex currVertex = pq.top().second;
        pq.pop();

        //Iterates through each adjacent vertex of the current vertex
        vector<Vertex> adjVertices = g_.getAdjacent(currVertex);
        for (int v = 0; v < adjVertices.size() - 1 && visited[adjVertices[v]] != true; ++v) {
            Vertex currAdjVertex = adjVertices[v];
            int currEdgeWeight = g_.getEdgeWeight(currVertex, currAdjVertex);
            if (dist[currAdjVertex] > dist[currVertex] + currEdgeWeight) {
                dist[currAdjVertex] = dist[currVertex] + currEdgeWeight;
                pq.push(make_pair(dist[currAdjVertex], currAdjVertex));
            }
        }
        visited[currVertex] = true;
    }
}

vector<Edge> Dijkstras(std::vector<std::vector<std::string>> data, Vertex a, Vertex b) {
    Dijkstras::Dijkstras(data);
    Dijkstras::Dijkstras_Helper(a, b);
}
