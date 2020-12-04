#include "fileio.h"

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