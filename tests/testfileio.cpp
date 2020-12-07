#include "../fileio.h"
#include "../cs225/catch/catch.hpp"
#include <vector>
using namespace fileio;

TEST_CASE("test_basic_fileio", "[fileio]") {
    std::vector<std::string> basic = file_to_vector("tests/data/basic.txt");
    REQUIRE(basic[0] == "this");
    REQUIRE(basic[1] == "is");
    REQUIRE(basic[2] == "a");
    REQUIRE(basic[3] == "test");
}

TEST_CASE("test_basic_tokenization", "[fileio]") {
    std::vector<std::string> lines = file_to_vector("tests/data/commas.txt");
    std::vector<std::vector<std::string>> tokens = csv_to_tokens(lines);
    REQUIRE(tokens[0][0] == "this");
    REQUIRE(tokens[0][1] == "is");
    REQUIRE(tokens[0][2] == "a");
    REQUIRE(tokens[0][3] == "test");
}

TEST_CASE("test_multiline_tokenization", "[fileio]") {
    std::vector<std::string> lines = file_to_vector("tests/data/longer.txt");
    std::vector<std::vector<std::string>> tokens = csv_to_tokens(lines);
    REQUIRE(lines.size() == 4);
    REQUIRE(tokens[0].size() == 7);
    REQUIRE(tokens[1].size() == 3);
    REQUIRE(tokens[2].size() == 1);
    REQUIRE(tokens[3].size() == 4);
}

