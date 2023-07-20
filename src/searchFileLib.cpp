#include "searchFileLib.h"

void searchFile(const std::filesystem::path& directory, const std::string& fileName) {
    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().filename() == fileName) {
            std::cout << "Файл найден: " << entry.path() << std::endl;
            return;
        }
    }
    std::cout << "Файл не найден." << std::endl;
}