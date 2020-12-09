#include "BFS.h"

#include <queue>
#include <vector>

/* constructor - takes in # of vertices (nodes) and starting vertex */
BFS::BFS(std::vector<Vertex> v, Vertex s) {
    for (Vertex i : v) {
        vertices.push_back(i);
    }

    adj = std::map<Vertex, std::vector<Vertex>>();

    isVisited = std::map<Vertex, bool>();
    for (Vertex i : vertices) {
        isVisited[i] = false;
    }
    isVisited[s] = true;
    queue.push(s);
}

/* second constructor - also takes in a vector of edges */
BFS::BFS(std::vector<Vertex> v, std::vector<Edge> e, Vertex s) {
    for (Vertex i : v) {
        vertices.push_back(i);
    }

    adj = std::map<Vertex, std::vector<Vertex>>();
    for (Edge j : e) {
        adj[j.source].push_back(j.dest);
        adj[j.dest].push_back(j.source);
    }

    isVisited = std::map<Vertex, bool>();
    for (Vertex i : vertices) {
        isVisited[i] = false;
    }
    isVisited[s] = true;
    queue.push(s);
}

/* destructor */
BFS::~BFS() {
    vertices.clear();
    adj.clear();
    queue.empty();
    isVisited.clear();
}

 /* helper function to add edge */
void BFS::addEdge(Vertex v, Vertex w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

 /* helper function to add edge */
void BFS::addEdge(Edge e) {
    adj[e.source].push_back(e.dest);
    adj[e.dest].push_back(e.source);
}

/* shows the node at the current top of the queue */
Vertex BFS::front(){
    return queue.front();
}

/* pops the top node of the queue */
void BFS::pop() {
    queue.pop();
}

/* conducts bfs traversal one step at a time, so you can get the top in between steps */
Vertex BFS::nextVertex() {
    std::list<int>::iterator i;

    while (!queue.empty()) {
        Vertex s = queue.front();

        for (Vertex i : adj[s]) {
            if (isVisited[i] == false) {
                isVisited[i] = true;
                queue.push(i);
                return i;
            }
        }

        queue.pop();
    }

    return NULL;
}

/* conducts the BFS traversal with starting node s */
void BFS::start() {
    std::list<int>::iterator i;

    while (!queue.empty()) {
        Vertex s = queue.front();
        queue.pop();

        for (Vertex i : adj[s]) {
            if (isVisited[i] == false) {
                isVisited[i] = true;
                queue.push(i);
            }
        }
    }
}

/* functions for testing purposes exclusively */
std::string BFS::printVertices() {
    string toReturn = "";
    for (Vertex v : vertices) {
        //std::cout << v << " ";
        toReturn += v + " ";
    }
    return toReturn;
}

/* functions for testing purposes exclusively */
std::string BFS::printEdges(Vertex v) {
    string toReturn = "";
    for (Vertex i : adj[v]) {
        //std::cout << i << " ";
        toReturn += v + " goes to " + i + " ";
    }
    return toReturn;
}