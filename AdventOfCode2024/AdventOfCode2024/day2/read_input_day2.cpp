#include "read_input_day2.h"

#include <fstream>
#include <ranges>
#include <string>

std::vector<std::vector<int>> read_input_day2(const std::filesystem::path& path)
{
    auto file = std::ifstream(path);

    auto vec_of_levels = std::vector<std::vector<int>>();
    auto row_data = std::string{};
    while (std::getline(file, row_data))
    {
        auto row = std::stringstream(row_data);
        auto val = std::string{};
        auto level = std::vector<int>{};
        while (std::getline(row, val, ' '))
        {
            level.push_back(std::stoi(val));
        }

        vec_of_levels.push_back(level);
    }

    return vec_of_levels;
}