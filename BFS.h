
#include <iostream>
#include <list>
#include <queue>

class Graph
{
public:

    // alternatively - we can pass in the start point 
    // with the constructor and save it as a private variable

    // for now i'll be referring to Nodes as ints

    /* constructor - takes in # of vertices (nodes) */
    Graph(int v);

    /* helper function to add edge */
    void addEdge(int v, int w);

    void pop();
    void peek() const;
    bool empty() const;

    /* conducts the BFS traversal with starting node s */
    void BFS(int s);

private:
    /* number of vertices */
    int vertices;

    /* Pointer to an array of adjacent vertices */
    std::list<int> *adj;
    std::queue<int> queue;
};