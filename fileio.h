#pragma once
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

namespace fileio {

std::vector<std::string> file_to_vector(const std::string & file);

std::vector<std::vector<std::string>> string_to_tokens(const std::vector<std::string> & csv);

}