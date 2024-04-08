#include "Serialization.h"
#include <vector>
#include <chrono>

void algorithmExample() {
    for (int i = 0; i < 100000000; i++) {
        int result = i * i;
    }
}

bool LinearSearch(const std::vector<BookData>& books, std::string& searchItem) {
    for (const auto& book : books) {
        if (book.title == searchItem) {
            return true;
        }
        try {
            if (book.pageCount == std::stoi(searchItem)) {
                return true;
            }
            if (book.genre == static_cast<Genre>(std::stoi(searchItem))) {
                return true;
            }
        }
        catch (...){
            continue;
        }
    }
    return false;
}

bool analyzeSpeed(const std::vector<BookData>& books, std::string& searchItem) {
    std::cout << "Testing the speed of the algorithm" << std::endl;
    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    //run the algorithm 10 times
    for (int i = 0; i < 10; i++) {
        if (LinearSearch(books, searchItem)) {
            end = std::chrono::steady_clock::now();
            duration = end - start;
            std::cout << "Item was found, the time to complete the algorithm " << duration.count() << " seconds" << std::endl;
            return true;
        }
    }
    end = std::chrono::steady_clock::now();
    duration = end - start;
    std::cout << "Item was not found, the time to complete the algorithm " << duration.count() << " seconds" << std::endl;
    return false;
}