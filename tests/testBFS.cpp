#include "../cs225/catch/catch.hpp"

#include "../BFS.h"

#include <vector>
#include <queue>
#include <map>

TEST_CASE("BFS constructor works", "[BFS]") {
    std::vector<Vertex> vertices = {"one", "two", "three"};
    BFS bfs(vertices, "one");

    REQUIRE(bfs.printVertices() == "one two three ");
}

TEST_CASE("BFS second constructor works", "[BFS]") {
    std::vector<Vertex> vertices = {"one", "two", "three"};
    std::vector<Edge> edges = std::vector<Edge>();
    edges.push_back(Edge("one", "two"));
    edges.push_back(Edge("one", "three"));
    BFS bfs(vertices, edges, "one");

    REQUIRE(bfs.printEdges("one") == "one goes to two one goes to three ");
    REQUIRE(bfs.printEdges("two") == "two goes to one ");
    REQUIRE(bfs.printEdges("three") == "three goes to one ");
}

TEST_CASE("BFS can add edges", "[BFS]") {
    std::vector<Vertex> vertices = {"one", "two", "three"};
    BFS bfs(vertices, "one");
    bfs.addEdge("one", "two");

    REQUIRE(bfs.printEdges("one") == "one goes to two ");
    REQUIRE(bfs.printEdges("two") == "two goes to one ");
    REQUIRE(bfs.printEdges("three") == "");
}

TEST_CASE("BFS pathing works", "[BFS]") {
    std::vector<Vertex> vertices = {"one", "two", "three"};
    BFS bfs(vertices, "one");
    bfs.addEdge(Edge("one", "two"));
    bfs.addEdge(Edge("one", "three"));

    bfs.nextVertex();
    bfs.nextVertex();

    REQUIRE(bfs.front() == "one");
    bfs.pop();
    REQUIRE(bfs.front() == "two");
    bfs.pop();
    REQUIRE(bfs.front() == "three");
    bfs.pop();
}