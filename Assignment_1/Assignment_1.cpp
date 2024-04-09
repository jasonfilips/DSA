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
    for (int i = 0; i < 100; i++) {
        if (linearSearch(books, searchItem)) {
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
        {"House of Leaves", Genre::Mystery, 736},
        {"Interview with the Vampire", Genre::GothicFiction, 308},
        {"The Lesser Dead", Genre::GothicFiction, 357},
        {"Memnoch the Devil", Genre::GothicFiction, 401},
        {"Those Across the River", Genre::HorrorFiction, 340},
        {"Vampire Hunter D Omnibus: Book One", Genre::Fiction, 640},
        {"Uzumaki", Genre::HorrorFiction, 648},
        {"The Resurrectionist: The Lost Work of Dr. Spencer Black", Genre::Mystery, 192}
    };

    std::string searchTerm = "The Resurrectionist: The Lost Work of Dr. Spencer Black";
    
    //Serialize data
    serializeData(books, "books.csv");

    //Deserialize data
    std::vector<BookData> deserializedBooks = deserializeData("books.csv");

    /*
    //Display deserialized data
    for (const auto& book : deserializedBooks) {
        std::cout << "Title: " << book.title << ", Genre: " << static_cast<int>(book.genre) << ", Page count: " << book.pageCount << std::endl;
    }*/
    
    if (analyzeSpeed(deserializedBooks, searchTerm)) {
        std::cout << "found" << std::endl;
    }
    else {
        std::cout << "not found" << std::endl;
    }

    std::string str1 = "The Lesser Dead";
    std::string str2 = "Those Across the River";

    if (str1 == str2) {
        std::cout << "a" << std::endl;
    }
    else if (str1 < str2) {
        std::cout << "b" << std::endl;
    }
    else {
        std::cout << "c" << std::endl;
    }

    return 0;
}