#pragma once

#include <filesystem>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> read_rules(const std::filesystem::path& path);
std::vector<std::vector<int>> read_updates(const std::filesystem::path& path);
