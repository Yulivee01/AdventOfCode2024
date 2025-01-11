#include "read_input_day9.h"

#include <fstream>
#include <ranges>
#include <string>

std::vector<int> read_input_day9(const std::filesystem::path& path)
{
    auto file = std::ifstream(path);

    auto row_data = std::string{};
    std::getline(file, row_data);

    return row_data
        | std::views::transform([](const auto str_elem) { return std::stoi(std::string{ str_elem }); })
        | std::ranges::to<std::vector>();
}