#include "Serialization.h"
#include <vector>

void algorithmExample() {
    for (int i = 0; i < 100000000; i++) {
        int result = i * i;
    }
}

//Linear search function
bool linearSearch(const std::vector<BookData>& books, std::string& searchItem) {
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

