#include "fileio.h"
#include <sstream>


namespace fileio {

std::vector<std::string> file_to_vector(const std::string & file) {
    std::ifstream text(file);
    std::vector<std::string> out;

    if (text.is_open()) {
        std::istream_iterator<std::string> iter(text);
        while (!iter.eof()) {
            out.push_back(*iter);
            ++iter;
        }
    }

    return out;
}

std::vector<std::vector<std::string>> csv_to_tokens(const std::vector<string> & csv) {
    std::vector<std::vector<std::string>> result;
    for (std::string s : csv) {
        result.push_back(split_string(s));
    }
    return result;
}

std::vector<std::string> split_string(std::string& to_split, const char& delim = ',') {
    std::vector<std::string> result;
    std::isstream stream(to_split);
    std::string token;
    while (std::getline(stream, token, delim)) {
        result.push_back(token);
    }
    return result;
}



}