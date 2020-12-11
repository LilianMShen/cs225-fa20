#include "../cs225/catch/catch.hpp"
#include "../landmark.h"
#include "../fileio.h"

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

TEST_CASE("test_landmark_path", "[landmark]") {
  std::vector<Edge> testPath = test.runLandmarkPath("1", "5", "0");
  REQUIRE(testPath.size() == 3);
  REQUIRE(testPath[0].getLabel() == "0-1");
  REQUIRE(testPath[1].getLabel() == "0-2");
  REQUIRE(testPath[2].getLabel() == "2-5");
}

TEST_CASE("test_landmark_path2", "[landmark]") {
  std::vector<Edge> testPath = test.runLandmarkPath("4", "7", "6");
  REQUIRE(testPath.size() == 5);
  REQUIRE(testPath[0].getLabel() == "2-4");
  REQUIRE(testPath[1].getLabel() == "5-2");
  REQUIRE(testPath[2].getLabel() == "6-5");
  REQUIRE(testPath[3].getLabel() == "6-5");
  REQUIRE(testPath[4].getLabel() == "5-7");
}

TEST_CASE("test_landmark_dataset", "[landmark]") {
  std::vector<std::string> predata = fileio::file_to_vector("tests/data/musae_ENGB_edges.csv");
  std::vector<std::vector<std::string>> afterdata = fileio::csv_to_tokens(predata);

  Landmark dataTest = Landmark(afterdata);
  std::vector<Edge> testPath;
  Graph testGraph = dataTest.getGraph();

  vector<Edge> path = dataTest.runLandmarkPath("15", "581", "15");

  REQUIRE(testGraph.vertexExists("15"));
}