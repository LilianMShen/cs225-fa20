#include "../cs225/catch/catch.hpp"

#include "../BFS.h"

#include <vector>
#include <queue>
#include <map>

TEST_CASE("BFS constructor works", "[BFS]") {
    std::vector<Vertex> vertices = {"one", "two", "three"};
    BFS bfs(vertices);

    REQUIRE(bfs.printVertices() == "one two three ");
}

TEST_CASE("BFS second constructor works", "[BFS]") {
    std::vector<Vertex> vertices = {"one", "two", "three"};
    std::vector<Edge> edges = std::vector<Edge>();
    edges.push_back(Edge("one", "two"));
    edges.push_back(Edge("one", "three"));
    BFS bfs(vertices, edges);

    REQUIRE(bfs.printEdges("one") == "one goes to two one goes to three ");
    REQUIRE(bfs.printEdges("two") == "two goes to one ");
    REQUIRE(bfs.printEdges("three") == "three goes to one ");
}

TEST_CASE("BFS can add edges", "[BFS]") {
    std::vector<Vertex> vertices = {"one", "two", "three"};
    BFS bfs(vertices);
    bfs.addEdge("one", "two");

    REQUIRE(bfs.printEdges("one") == "one goes to two ");
    REQUIRE(bfs.printEdges("two") == "two goes to one ");
    REQUIRE(bfs.printEdges("three") == "");
}