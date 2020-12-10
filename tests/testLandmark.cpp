#include "../cs225/catch/catch.hpp"

#include "../landmark.h"

#include <vector>
#include <string>

std::vector<std::vector<std::string>> data = {
    {"0", "1"},
    {"0", "2"},
    {"0", "4"},
    {"2", "4"},
    {"2", "5"},
    {"1", "3"},
    {"3", "5"},
    {"3", "7"},
    {"5", "6"},
    {"5", "7"}
};
Landmark test = Landmark(data);
Graph graph = test.getGraph();

TEST_CASE("test_landmark_constructor_vertices_edges", "[landmark]") {
    REQUIRE(graph.edgeExists("0", "1") == true);
    REQUIRE(graph.edgeExists("0", "2") == true);
    REQUIRE(graph.edgeExists("0", "4") == true);
    REQUIRE(graph.edgeExists("2", "4") == true);
    REQUIRE(graph.edgeExists("2", "5") == true);
    REQUIRE(graph.edgeExists("1", "3") == true);
    REQUIRE(graph.edgeExists("3", "5") == true);
    REQUIRE(graph.edgeExists("3", "7") == true);
    REQUIRE(graph.edgeExists("5", "6") == true);
    REQUIRE(graph.edgeExists("5", "7") == true);
}