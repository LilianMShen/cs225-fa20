//#include "catch/catch_amalgamated.hpp"

#include "../cs225/catch/catch.hpp"

#include "../BFS.h"

#include <vector>
#include <queue>
#include <map>

TEST_CASE("BFS correctly constructs", "[BFS]") {
    std::vector<Vertex> vertices = {"one", "two", "three"};
    BFS bfs(vertices);

    REQUIRE(bfs.printVertices() == "one two three ");
}