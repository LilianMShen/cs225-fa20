#include "BFS.h"

#include <list>
#include <queue>
#include <vector>

/* constructor - takes in # of vertices (nodes) */
BFS::BFS(std::vector<Vertex> v) {
    for (Vertex i : v) {
        vertices.push_back(i);
    }
    adj = std::map<Vertex, std::vector<Vertex>>();
}

/* second constructor - also takes in a vector of edges */
BFS::BFS(std::vector<Vertex> v, std::vector<Edge> e) {
    for (Vertex i : v) {
        vertices.push_back(i);
    }

    adj = std::map<Vertex, std::vector<Vertex>>();
    for (Edge j : e) {
        adj[j.source].push_back(j.dest);
        adj[j.dest].push_back(j.source);
    }
}

/* destructor */
BFS::~BFS() {
    vertices.clear();
    adj.clear();
    queue.empty();
}

void BFS::addEdge(Vertex v, Vertex w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void BFS::addEdge(Edge e) {
    adj[e.source].push_back(e.dest);
    adj[e.dest].push_back(e.source);
}

void BFS::start(Vertex s) {
    std::map<Vertex, bool> isVisited = std::map<Vertex, bool>();
    for (Vertex i : vertices) {
        isVisited[i] = false;
    }

    isVisited[s] = true;
    queue.push(s);

    std::list<int>::iterator i;

    while (!queue.empty()) {
        s = queue.front();
        queue.pop();

        for (Vertex i : adj[s]) {
            if (isVisited[i] == false) {
                isVisited[i] = true;
                queue.push(i);
            }
        }
    }
}