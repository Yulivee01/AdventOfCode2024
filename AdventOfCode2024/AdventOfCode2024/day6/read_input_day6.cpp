#include "read_input_day6.h"

#include <fstream>

std::vector<std::string> read_input_day6(const std::filesystem::path& path)
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
