#pragma once
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

namespace fileio {

std::vector<std::string> file_to_vector(const std::string & file);

std::vector<std::vector<std::string>> csv_to_tokens(const std::vector<std::string> & csv);

std::vector<std::string> split_string(std::string& to_split, const char& delim);

}