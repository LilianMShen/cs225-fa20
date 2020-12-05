#include "BFS.h"

#include <list>
#include <queue>
#include <vector>

BFS::BFS(std::list<Vertex> v) {
    //vertices = v;
    //adj = new std::list<int>[vertices];
    for (Vertex i : v) {
        vertices.push_back(i);
    }
    adj = std::map<Vertex, std::list<Vertex>>();
}

BFS::~BFS() {
    adj.clear();
}

void BFS::addEdge(Vertex v, Vertex w) {
    //adj[v].push_back(w);
    adj[v].push_back(w);
}

void BFS::start(Vertex s) {
    std::map<Vertex, bool> isVisited = std::map<Vertex, bool>();
    for (Vertex i : vertices) {
        isVisited[i] = false;
    }
    /*
    bool * visited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }
    visited[s] = true;
    queue.push(s);
    */

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