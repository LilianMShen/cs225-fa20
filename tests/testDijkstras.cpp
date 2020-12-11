#include "../cs225/catch/catch.hpp"
#include "../dijkstras.h"
#include "../fileio.h"

#include <vector>
#include <string>

/*
README

If you want to see all the vertices being visited
in the priority queue and all the adjacent vertices
being checked, uncomment the print statements in
dijkstras.cpp.
*/

//Tests for weighted graph
std::vector<std::vector<std::string>> data_1 = {
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
Dijkstras test_1 = Dijkstras(data_1);
Graph graph_1 = test_1.getGraph();

TEST_CASE("test_dijkstras_constructor_vertices_edges", "[dijkstras]") {
    REQUIRE(graph_1.edgeExists("2", "1") == true);
    REQUIRE(graph_1.edgeExists("3", "1") == true);
    REQUIRE(graph_1.edgeExists("5", "4") == true);
    REQUIRE(graph_1.edgeExists("4", "3") == true);
    REQUIRE(graph_1.edgeExists("5", "2") == true);
    REQUIRE(graph_1.edgeExists("6", "4") == true);
    REQUIRE(graph_1.edgeExists("7", "5") == true);
    REQUIRE(graph_1.edgeExists("6", "5") == true);
    REQUIRE(graph_1.edgeExists("7", "6") == true);
    REQUIRE(graph_1.edgeExists("8", "6") == true);
}

TEST_CASE("test_dijkstras_constructor_weights", "[dijkstras]") {
    REQUIRE(graph_1.getEdgeWeight("2", "1") == 50);
    REQUIRE(graph_1.getEdgeWeight("3", "1") == 21);
    REQUIRE(graph_1.getEdgeWeight("5", "4") == 53);
    REQUIRE(graph_1.getEdgeWeight("4", "3") == 57);
    REQUIRE(graph_1.getEdgeWeight("5", "2") == 42);
    REQUIRE(graph_1.getEdgeWeight("6", "4") == 63);
    REQUIRE(graph_1.getEdgeWeight("7", "5") == 57);
    REQUIRE(graph_1.getEdgeWeight("6", "5") == 40);
    REQUIRE(graph_1.getEdgeWeight("7", "6") == 51);
    REQUIRE(graph_1.getEdgeWeight("8", "6") == 1);
}

TEST_CASE("test_dijkstras_1", "[dijkstras]") {
    vector<Edge> path_1 = test_1.Dijkstras_Helper("1", "8");

    REQUIRE(path_1[0].getWeight() == 50);
    REQUIRE(path_1[1].getWeight() == 42);
    REQUIRE(path_1[2].getWeight() == 40);
    REQUIRE(path_1[3].getWeight() == 1);
}

//Test for single heavy-weight path vs. many light-weight paths
TEST_CASE("test_dijkstras_2", "[dijkstras]") {
    std::vector<std::vector<std::string>> data_2 = {
        {"1", "3", "1"},
        {"3", "4", "1"},
        {"4", "5", "1"},
        {"5", "6", "1"},
        {"6", "7", "1"},
        {"7", "8", "1"},
        {"8", "2", "1"},
        {"1", "2", "10"},
    };
    Dijkstras test_2 = Dijkstras(data_2);
    Graph graph_2 = test_2.getGraph();
    vector<Edge> path_2 = test_2.Dijkstras_Helper("1", "2");

    REQUIRE(path_2.size() == 7);
    REQUIRE(path_2[0].getWeight() == 1);
    REQUIRE(path_2[1].getWeight() == 1);
    REQUIRE(path_2[2].getWeight() == 1);
    REQUIRE(path_2[3].getWeight() == 1);
    REQUIRE(path_2[4].getWeight() == 1);
    REQUIRE(path_2[5].getWeight() == 1);
    REQUIRE(path_2[6].getWeight() == 1);
}

//Test for unweighted graph
TEST_CASE("test_dijkstras_3", "[dijkstras]") {
    std::vector<std::vector<std::string>> data_3 = {
        {"3", "7", "1"},
        {"3", "4", "1"},
        {"7", "4", "1"},
        {"7", "6", "1"},
        {"6", "4", "1"},
        {"5", "6", "1"},
        {"5", "4", "1"}
    };
    Dijkstras test_3 = Dijkstras(data_3);
    Graph graph_3 = test_3.getGraph();
    vector<Edge> path_3 = test_3.Dijkstras_Helper("3", "6");

    REQUIRE(path_3.size() == 2);
    REQUIRE(path_3[0].getLabel() == "3-4");
    REQUIRE(path_3[1].getLabel() == "4-6");
}

//Test for AIO Dijkstra's Function
TEST_CASE("test_dijkstras_AIO", "[dijkstras]") {
    std::vector<std::vector<std::string>> data_4 = {
        {"1", "0", "3"},
        {"1", "3", "2"},
        {"0", "2", "1"},
        {"3", "2", "5"},
    };
    Dijkstras test_4 = Dijkstras(data_4);
    Graph graph_4 = test_4.getGraph();
    vector<Edge> path_4 = test_4.Dijkstras_Helper("0", "3");

    REQUIRE(path_4[0].getLabel() == "0-1");
    REQUIRE(path_4[1].getLabel() == "1-3");
}

//Dataset test
TEST_CASE("test_dijkstras_dataset", "[dijkstras]") {
    std::vector<std::string> predata = fileio::file_to_vector("tests/data/musae_ENGB_edges.csv");
    std::vector<std::vector<std::string>> afterdata = fileio::csv_to_tokens(predata);

    Dijkstras test_5 = Dijkstras(afterdata);
    Graph graph_5 = test_5.getGraph();

    //optional route of 15 -> 343 -> 6592 -> 581
    vector<Edge> path_5 = test_5.Dijkstras_Helper("15", "581");

    REQUIRE(graph_5.vertexExists("15"));
}
