#include "../cs225/catch/catch.hpp"
#include "../dijkstras.h"

#include <vector>
#include <string>

//Tests for weighted graph
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
Dijkstras test = Dijkstras(data);
Graph graph = test.getGraph();

TEST_CASE("test_dijkstras_constructor_vertices_edges", "[dijkstras]") {
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

TEST_CASE("test_dijkstras_constructor_weights", "[dijkstras]") {
    REQUIRE(graph.getEdgeWeight("2", "1") == 50);
    REQUIRE(graph.getEdgeWeight("3", "1") == 21);
    REQUIRE(graph.getEdgeWeight("5", "4") == 53);
    REQUIRE(graph.getEdgeWeight("4", "3") == 57);
    REQUIRE(graph.getEdgeWeight("5", "2") == 42);
    REQUIRE(graph.getEdgeWeight("6", "4") == 63);
    REQUIRE(graph.getEdgeWeight("7", "5") == 57);
    REQUIRE(graph.getEdgeWeight("6", "5") == 40);
    REQUIRE(graph.getEdgeWeight("7", "6") == 51);
    REQUIRE(graph.getEdgeWeight("8", "6") == 1);
}

vector<Edge> path = test.Dijkstras_Helper("1", "8");

TEST_CASE("test_dijkstras_1", "[dijkstras]") {
    REQUIRE(path[1].getLabel() == "1-3");
    REQUIRE(path[1].getWeight() == 21);
}