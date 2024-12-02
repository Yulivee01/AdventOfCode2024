#pragma once

#include <array>
#include <filesystem>
#include <utility>
#include <vector>

struct levels
{
    std::array<int, 5> level_data;
};

std::pair<std::vector<int>, std::vector<int>> read_input_day2(const std::filesystem::path& path);
