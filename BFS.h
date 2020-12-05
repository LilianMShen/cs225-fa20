
#include <iostream>
#include <list>
#include <queue>
#include <map>

#include "Dijkstras/graph.h"
#include "Dijkstras/edge.h"

class BFS
{
public:

    // alternatively - we can pass in the start point 
    // with the constructor and save it as a private variable

    // for now i'll be referring to Nodes as ints

    /* constructor - takes in # of vertices (nodes) */
    BFS(std::list<Vertex> vertices);

    /* helper function to add edge */
    void addEdge(Vertex v, Vertex w);

    /* conducts the BFS traversal with starting node s */
    void start(Vertex s);

private:
    /* number of vertices */
    std::list<Vertex> vertices;
    //int vertices;

    /* Pointer to an array of adjacent vertices */
    //mutable unordered_map<Vertex, unordered_map<Vertex, Edge>> *adj;
    //std::list<Vertex> *adj;
    std::map<Vertex, std::list<Vertex>> adj;

    /* the queue of vertices we will visit */
    std::queue<Vertex> queue;
};