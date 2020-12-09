#include <queue>
#include <utility>
#include <map>
#include <functional>
#include <sstream>
#include <string>

#include "dijkstras.h"
#include "graph.h"

Dijkstras::Dijkstras(std::vector<std::vector<std::string>> data) : g_(true, false) {
    for (unsigned i = 0; i < data.size(); ++i) {
        //Inserts all vertices
        if (g_.vertexExists(data[i][0]) == false) {
            g_.insertVertex(data[i][0]);
        }
        if (g_.vertexExists(data[i][1]) == false) {
            g_.insertVertex(data[i][1]);
        }
        if (g_.edgeExists(data[i][0], data[i][1]) == false) {
            g_.insertEdge(data[i][0], data[i][1]);

            //Converts weight (string of digits) to integer
            std::stringstream temp(data[i][2]);
            int weight = 0;
            temp >> weight;
            g_.setEdgeWeight(data[i][0], data[i][1], weight);
        }
    }
}

std::vector<Edge> Dijkstras::Dijkstras_Helper(Vertex a, Vertex b) {
    //Definitions
    const int INF = 0x3f3f3f3f;
    typedef int distance;
    typedef std::pair<distance, Vertex> vDistPair;

    //Initializes map of distance for each vertex, all distances set to infinity at start
    std::vector<Vertex> allVertices = g_.getVertices();
    std::unordered_map<Vertex, distance> dist;
    for (unsigned v = 0; v < allVertices.size(); ++v) {
        dist[allVertices[v]] = INF;
    }
    dist[a] = 0;

    //Initialize a map that maps current node to its previous node.
    std::unordered_map<Vertex, Vertex> next = { {a, ""} };

    //Initialize priority queue (min-heap), with source vertex's distance = 0
    std::priority_queue<vDistPair, std::vector<vDistPair>, std::greater<vDistPair>> pq;
    pq.push(make_pair(0, a));

    //Initialize unordered map of visited/unvisited vertices
    std::unordered_map<Vertex, bool> visited;
    for (unsigned v = 0; v < allVertices.size(); ++v) {
        visited[allVertices[v]] = false;
    }

    //Loops until it reaches destination vertex
    while (pq.empty() == false && pq.top().second != b) {
        Vertex currVertex = pq.top().second;
        pq.pop();

        //Iterates through each adjacent vertex of the current vertex
        std::vector<Vertex> adjVertices = g_.getAdjacent(currVertex);
        for (unsigned v = 0; v < adjVertices.size() && visited[adjVertices[v]] != true; ++v) {
            Vertex adjVertex = adjVertices[v];
            int edgeWeight = g_.getEdgeWeight(currVertex, adjVertex);
            if (dist[adjVertex] > dist[currVertex] + edgeWeight) {
                dist[adjVertex] = dist[currVertex] + edgeWeight;
                pq.push(make_pair(dist[adjVertex], adjVertex));
                next[currVertex] = adjVertex;
            }
        }
        visited[currVertex] = true;
    }

    //Extracts shortest path from previous map
    vector<Edge> path;
    for (Vertex curr = a; curr != b; curr = next[curr]) {
        int weight = g_.getEdgeWeight(curr, next[curr]);
        path.push_back(Edge(curr, next[curr], weight, curr + "-" + next[curr]));
    }
    return path;
}

/*std::vector<Edge> runDijkstras(std::vector<std::vector<std::string>> data, Vertex a, Vertex b) {
    Dijkstras::Dijkstras(data);
    Dijkstras::Dijkstras_Helper(a, b);
}*/

Graph Dijkstras::getGraph() {
    return g_;
}
