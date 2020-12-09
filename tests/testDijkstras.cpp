#include "../cs225/catch/catch.hpp"

#include "../dijkstras.h"

#include <vector>
#include <string>

std::vector<std::vector<std::string>> data = {
    {"1", "2", "50"},
    {"1", "3", "21"},
    {"4", "5", "53"},
    {"3", "4", "57"},
    {"2", "5", "42"},
    {"4", "6", "63"},
    {"5", "7", "57"},
    {"5", "6", "40"},
    {"6", "7", "51"},
    {"6", "8", "1"}
};

TEST_CASE("test_dijkstras_constructor_edges", "[dijkstras]") {
    Dijkstras::Dijkstras test(data);
    Graph graph = test.getGraph();
    REQUIRE(graph.edgeExists("2", "1") == true);
    REQUIRE(graph.edgeExists("3", "1") == true);
    REQUIRE(graph.edgeExists("5", "4") == true);
    REQUIRE(graph.edgeExists("4", "3") == true);
    REQUIRE(graph.edgeExists("5", "2") == true);
    REQUIRE(graph.edgeExists("6", "4") == true);
    REQUIRE(graph.edgeExists("7", "5") == true);
    REQUIRE(graph.edgeExists("6", "5") == true);
    REQUIRE(graph.edgeExists("7", "6") == true);
    REQUIRE(graph.edgeExists("8", "6") == true);
}