#include "Serialization.h"
#include <span>

void algorithmExample() {
    for (int i = 0; i < 100000000; i++) {
        int result = i * i;
    }
}

//Linear search function
bool linearSearch(std::span<BookData> books, std::string_view searchItem) {
    for (const auto& book : books) {
        if (book.title == searchItem) {
            return true;
        }
        try {
            if (book.pageCount == std::atoi(searchItem.data())) {
                return true;
            }
            if (book.genre == static_cast<Genre>(std::atoi(searchItem.data()))) {
                return true;
            }
        }
        catch (...){
            continue;
        }
    }
    return false;
}

