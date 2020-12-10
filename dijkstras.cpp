#include <queue>
#include <utility>
#include <map>
#include <functional>
#include <sstream>
#include <string>
#include <iostream>

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
    std::unordered_map<Vertex, Vertex> prev;

    //Initialize priority queue (min-heap), with source vertex's distance = 0
    std::priority_queue<vDistPair, std::vector<vDistPair>, std::greater<vDistPair>> pq;
    pq.push(make_pair(0, a));

    //Initialize unordered map of visited/unvisited vertices
    std::unordered_map<Vertex, bool> visited;
    for (unsigned v = 0; v < allVertices.size(); ++v) {
        visited[allVertices[v]] = false;
    }

    //Loops until it reaches destination vertex pq.empty() == false && 
    while (pq.top().second != b) {
        Vertex currVertex = pq.top().second;
        pq.pop();

        std::cout<<"Current Vertex: " + currVertex<<endl;

        //Iterates through each adjacent vertex of the current vertex
        std::vector<Vertex> adjVertices = g_.getAdjacent(currVertex);
        for (unsigned v = 0; v < adjVertices.size(); ++v) {
            if (visited[adjVertices[v]] == true) {
                continue;
            }
            else {
                Vertex adjVertex = adjVertices[v];

                std::cout<<"Checking neighbor " + adjVertex + "..."<<endl;
                
                int edgeWeight = g_.getEdgeWeight(currVertex, adjVertex);
                if (dist[adjVertex] > dist[currVertex] + edgeWeight) {
                    dist[adjVertex] = dist[currVertex] + edgeWeight;
                    pq.push(make_pair(dist[adjVertex], adjVertex));
                    prev[adjVertex] = currVertex;
                }
            }
        }
        visited[currVertex] = true;
    }
    std::cout<<"Search complete! Extracting path..."<<endl;

    //Extracts shortest path from previous map
    vector<Edge> path;
    Vertex curr = b;
    Vertex currprev = prev[curr];
    int weight = 0;
    for (curr = b; curr != a; curr = prev[curr]) {
        weight = g_.getEdgeWeight(prev[curr], curr);
        std::vector<Edge>::iterator it = path.begin();
        it = path.insert(it, Edge(prev[curr], curr, weight, prev[curr] + "-" + curr));
    }
    for (unsigned i = 0; i < path.size(); ++i) {
        std::cout<<path[i].getLabel()<<endl;
    }
    return path;
}

std::vector<Edge> runDijkstras(std::vector<std::vector<std::string>> data, Vertex a, Vertex b) {
    Dijkstras dijkstras = Dijkstras(data);
    return dijkstras.Dijkstras_Helper(a, b);
}

Graph Dijkstras::getGraph() {
    return g_;
}
