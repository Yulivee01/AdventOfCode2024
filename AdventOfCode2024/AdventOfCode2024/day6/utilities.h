#pragma once

#include <cstddef>
#include <string>
#include <vector>

enum class direction
{
    up,
    down,
    left,
    right
};

struct position
{
    ptrdiff_t x{};
    ptrdiff_t y{};
};

position find_start(const std::vector<std::string>& map);
void move(position& pos, const direction& dir);
void rotate(direction& dir);
void correct_position(position& pos, const direction& dir);