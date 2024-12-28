#include "read_input_day7.h"

#include <fstream>

std::vector<calibration> read_input_day7(const std::filesystem::path& path)
{
    auto file = std::ifstream(path);

    auto calibrations = std::vector<calibration>();
    auto row_data = std::string{};
    while (std::getline(file, row_data))
    {
        const auto pos = static_cast<ptrdiff_t>(row_data.find(':'));
        const auto result = std::stoull(std::string(row_data.begin(), row_data.begin() + pos));

        auto row = std::stringstream(std::string(row_data.begin() + pos + 2, row_data.end()));
        auto val = std::string{};
        auto numbers = std::vector<int>{};
        while (std::getline(row, val, ' '))
        {
            numbers.push_back(std::stoi(val));
        }

        calibrations.emplace_back(result, numbers);
    }

    return calibrations;
}
