#include "BFS.h"

#include <list>
#include <queue>
#include <vector>

Graph::Graph(int v) {
    vertices = v;
    adj = new std::list<int>[vertices];
}

Graph::~Graph() {
    delete[] adj;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    bool * visited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    visited[s] = true;
    queue.push(s);

    std::list<int>::iterator i;

    while (!queue.empty()) {
        s = queue.front();
        queue.pop();

        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }
}