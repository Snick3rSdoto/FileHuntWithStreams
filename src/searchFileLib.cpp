#include "searchFileLib.h"


// const unsigned int MAX_THREADS = 8;

std::atomic<bool> fileFound(false);

void searchFileThreaded(const std::filesystem::path &directory, const std::string &fileName, int maxThreads) {
    try {
        std::list<std::thread> threads;
        for (const auto &entry : std::filesystem::directory_iterator(directory, std::filesystem::directory_options::skip_permission_denied)) {
            if (fileFound) { break; }

            if (threads.size() >= maxThreads) {
                threads.front().join();
                threads.pop_front();
            }
            if (std::filesystem::is_directory(entry.path()) && threads.size() < maxThreads) {
                threads.push_back(std::thread(searchFileSingle, entry.path(), fileName));
            }
        }
        for (auto &thread : threads) { thread.join(); }

        if (!fileFound) {std::cout << "File not found" << std::endl; }
    }
    catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}

void searchFileSingle(const std::filesystem::path &directory, const std::string &fileName) {
    for (const auto &entry : std::filesystem::recursive_directory_iterator(directory, std::filesystem::directory_options::skip_permission_denied)) {
        if (fileFound) { return; }

        if (entry.path().filename() == fileName) {
            std::cout << "File found: " << entry.path() << std::endl;
            fileFound = true;
            return;
        }
    }
}