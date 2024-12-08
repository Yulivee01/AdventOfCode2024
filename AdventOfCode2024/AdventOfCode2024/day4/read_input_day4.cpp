#include "read_input_day4.h"

#include <fstream>

std::vector<std::string> read_input_day4(const std::filesystem::path& path)
{
    auto file = std::ifstream(path);
    auto line = std::string();
    auto input = std::vector<std::string>();
    while (file >> line)
    {
        input.push_back(line);
    }

    return input;
}
