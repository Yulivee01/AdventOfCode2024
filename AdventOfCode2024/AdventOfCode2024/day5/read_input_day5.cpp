#include "read_input_day5.h"

#include <fstream>

std::vector<std::pair<int, int>> read_rules(const std::filesystem::path& path)
{
    auto rules = std::vector<std::pair<int, int>>();

    auto file = std::ifstream(path);
    auto pair = std::string{};
    while (file >> pair)
    {
        const auto pos = static_cast<ptrdiff_t>(pair.find('|'));
        rules.emplace_back(std::stoi(std::string(pair.begin(), pair.begin() + pos)),
            std::stoi(std::string(pair.begin() + pos + 1, pair.end())));
    }

    return rules;
}

std::vector<std::vector<int>> read_updates(const std::filesystem::path& path)
{
    auto file = std::ifstream(path);

    auto updates = std::vector<std::vector<int>>();
    auto row_data = std::string{};
    while (std::getline(file, row_data))
    {
        auto row = std::stringstream(row_data);
        auto val = std::string{};
        auto update = std::vector<int>{};
        while (std::getline(row, val, ','))
        {
            update.push_back(std::stoi(val));
        }

        updates.push_back(update);
    }

    return updates;
}
