#include "searchFileLib.h"

void searchFile(const std::filesystem::path& directory, const std::string& fileName) {
    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
        // std::cout << entry.path() << std::endl;
        if (entry.path().filename() == fileName) {
            std::cout << "File will find: " << entry.path() << std::endl;
            return;
        }
    }
    std::cout << "File not found." << std::endl;
}