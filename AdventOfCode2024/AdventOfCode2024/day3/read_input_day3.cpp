#include "read_input_day3.h"

#include <fstream>

std::string read_input_day3(const std::filesystem::path& path)
{
    auto file = std::ifstream(path);
    auto line = std::string();
    auto full_string = std::string();
    while (file >> line)
    {
        full_string += line;
    }

    return full_string;
}