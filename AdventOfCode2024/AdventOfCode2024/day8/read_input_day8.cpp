#include "read_input_day8.h"

#include <fstream>

std::pair<std::string, ptrdiff_t> read_input_day8(const std::filesystem::path& path)
{
    auto file = std::ifstream(path);
    auto line = std::string();
    auto full_string = std::string();
    ptrdiff_t row_size = 0;
    while (file >> line)
    {
        row_size = std::ssize(line);
        full_string += line;
    }

    return { full_string, row_size };
}
