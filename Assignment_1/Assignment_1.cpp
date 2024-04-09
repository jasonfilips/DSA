#include "Serialization.h"
#include "LinearSearch.h"
#include "BinarySearchTree.h"
#include <vector>
#include <chrono>

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

int main()
{
    //Example
    std::vector<BookData> books = {
        {"The Temple of the Golden Pavilion", Genre::Novel, 264},
        {"Legend of the Galactic Heroes: Dawn", Genre::SpaceOpera, 292},
        {"House of Leaves", Genre::Mystery, 736}
    };

    std::string searchTerm = "266";
    
    //Serialize data
    serializeData(books, "books.csv");

    //Deserialize data
    std::vector<BookData> desirializedBooks = deserializeData("books.csv");

    /*
    //Display deserialized data
    for (const auto& book : desirializedBooks) {
        std::cout << "Title: " << book.title << ", Genre: " << static_cast<int>(book.genre) << ", Page count: " << book.pageCount << std::endl;
    }*/
    
    if (analyzeSpeed(desirializedBooks, searchTerm)) {
        std::cout << "found" << std::endl;
    }
    else {
        std::cout << "not found" << std::endl;
    }
    return 0;
}