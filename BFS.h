
#include <iostream>
#include <vector>
#include <queue>
#include <map>

#include "Dijkstras/graph.h"
#include "Dijkstras/edge.h"

class BFS
{
public:
    /* constructor - takes in # of vertices (nodes) */
    BFS(std::vector<Vertex> v);

    /* second constructor - also takes in a vector of edges */
    BFS(std::vector<Vertex> v, std::vector<Edge> e);

    /* destructor */
    ~BFS();

    /* helper function to add edge */
    void addEdge(Vertex v, Vertex w);
    void addEdge(Edge e);

    /* conducts the BFS traversal with starting node s */
    void start(Vertex s);

    /* functions for testing purposes exclusively */
    std::string printVertices();
    std::string printEdges(Vertex v);

private:
    /* number of vertices */
    std::vector<Vertex> vertices;

    /* Pointer to an array of adjacent vertices */
    std::map<Vertex, std::vector<Vertex>> adj;

    /* the queue of vertices we will visit */
    std::queue<Vertex> queue;
};