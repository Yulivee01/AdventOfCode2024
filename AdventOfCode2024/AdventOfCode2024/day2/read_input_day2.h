#pragma once

#include <filesystem>
#include <vector>

struct levels
{
    std::vector<int> level_data;
};

std::vector<levels> read_input_day2(const std::filesystem::path& path);
