#include "read_input_day2.h"

#include <fstream>
#include <ranges>
#include <string>

std::vector<levels> read_input_day2(const std::filesystem::path& path)
{
    auto file = std::ifstream(path);

    auto vec_of_levels = std::vector<levels>();
    auto row_data = std::string{};
    while (std::getline(file, row_data))
    {
        auto row = std::stringstream(row_data);
        auto val = std::string{};
        auto level = levels{};
        while (std::getline(row, val, ' '))
        {
            level.level_data.push_back(std::stoi(val));
        }

        vec_of_levels.push_back(level);
    }

    return vec_of_levels;
}