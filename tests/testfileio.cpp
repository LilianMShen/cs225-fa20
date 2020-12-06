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

