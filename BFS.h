
#include <iostream>
#include <vector>
#include <queue>
#include <map>

#include "graph.h"
#include "edge.h"

class BFS
{
public:
    /* constructor - takes in # of vertices (nodes) */
    BFS(std::vector<Vertex> v, Vertex s);

    /* second constructor - also takes in a vector of edges */
    BFS(std::vector<Vertex> v, std::vector<Edge> e, Vertex s);

    /* destructor */
    ~BFS();

    /* helper function to add edge */
    void addEdge(Vertex v, Vertex w);
    void addEdge(Edge e);

    /* shows the node at the current front of the queue */
    Vertex front();

    /* pops the front node of the queue */
    void pop();

    /* conducts bfs traversal one step at a time, so you can get the top in between steps */
    Vertex nextVertex();

    /* conducts the BFS traversal */
    void start();

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

    /* a map of all vertices to whether they have or have not been visited */
    std::map<Vertex, bool> isVisited;
};