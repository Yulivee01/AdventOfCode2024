#include "read_input_day2.h"

#include <fstream>

std::pair<std::vector<int>, std::vector<int>> read_input_day2(const std::filesystem::path& path)
{
    auto vec1 = std::vector<int>();
    auto vec2 = std::vector<int>();

    auto file = std::ifstream(path);
    auto a = 0;
    auto b = 0;
    while (file >> a >> b)
    {
        vec1.push_back(a);
        vec2.push_back(b);
    }

    return { vec1, vec2 };
}