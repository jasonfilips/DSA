#include "Serialization.h"
#include "LinearSearch.h"
#include "BinaryTreeSearch.h"
#include "BinarySearch.h"
#include <vector>
#include <chrono>

bool analyzeSpeed(const std::vector<BookData>& books, std::string& searchItem) {
    std::cout << "Testing the speed of the algorithms" << std::endl;

    auto linearSearchStart = std::chrono::steady_clock::now();
    auto linearSearchEnd = std::chrono::steady_clock::now();
    std::chrono::duration<double> linearSearchTotalTime;

    auto binaryTreeSearchStart = std::chrono::steady_clock::now();
    auto binaryTreeSearchEnd = std::chrono::steady_clock::now();
    std::chrono::duration<double> binaryTreeSearchTotalTime;

    auto binarySearchStart = std::chrono::steady_clock::now();
    auto binarySearchEnd = std::chrono::steady_clock::now();
    std::chrono::duration<double> binarySearchTotalTime;

    bool binaryTreeSearchFound = false;
    bool binarySearchFound = false;
    bool linearSearchFound = false;

    BinaryTreeSearch bst(books);

    //run the algorithm 100000 times
    for (int i = 0; i < 100000; i++) {
        linearSearchStart = std::chrono::steady_clock::now();
        if (linearSearch(books, searchItem)) {
            //std::cout << "Item was found using Linear Search, the time to complete the algorithm " << linearSearchTotalTime.count() << " seconds" << std::endl;
            linearSearchFound = true;
        }
        linearSearchEnd = std::chrono::steady_clock::now();

        if (i == 0) {
            linearSearchTotalTime = linearSearchEnd-linearSearchStart;
        }
        else {
            linearSearchTotalTime += linearSearchEnd - linearSearchStart;
        }

        binaryTreeSearchStart = std::chrono::steady_clock::now();
        if (bst.search(searchItem)) {
            //std::cout << "Item was found using Binary Tree Search, the time to complete the algorithm " << binaryTreeSearchTotalTime.count() << " seconds" << std::endl;
            binaryTreeSearchFound = true;
        }
        binaryTreeSearchEnd = std::chrono::steady_clock::now();

        if (i == 0) {
            binaryTreeSearchTotalTime = binaryTreeSearchEnd - binaryTreeSearchStart;
        }
        else {
            binaryTreeSearchTotalTime += binaryTreeSearchEnd - binaryTreeSearchStart;
        }

        binarySearchStart = std::chrono::steady_clock::now();
        if (binarySearch(books,searchItem)) {
            //std::cout << "Item was found using Binary Search, the time to complete the algorithm " << binarySearchTotalTime.count() << " seconds" << std::endl;
            binarySearchFound = true;
        }
        binarySearchEnd = std::chrono::steady_clock::now();

        if (i == 0) {
            binarySearchTotalTime = binarySearchEnd - binarySearchStart;
        }
        else {
            binarySearchTotalTime += binarySearchEnd - binarySearchStart;
        }
    }

    std::cout << "It took Linear Search " << linearSearchTotalTime.count() << " seconds to complete" << std::endl;
    if (linearSearchFound) {
        std::cout << "Item was found using Linear Search." << std::endl;
    }
    else {
        std::cout << "Item was not found using Linear Search." << std::endl;
    }

    std::cout << "It took Binary Tree Search " << binaryTreeSearchTotalTime.count() << " seconds to complete" << std::endl;
    if (binaryTreeSearchFound) {
        std::cout << "Item was found using Binary Tree Search." << std::endl;
    }
    else {
        std::cout << "Item was not found using Binary Tree Search." << std::endl;
    }

    std::cout << "It took Binary Search " << binarySearchTotalTime.count() << " seconds to complete" << std::endl;
    if (binarySearchFound) {
        std::cout << "Item was found using Binary Search." << std::endl;
    }
    else {
        std::cout << "Item was not found using Binary Search." << std::endl;
    }

    return binaryTreeSearchFound == linearSearchFound && binaryTreeSearchFound == binarySearchFound;
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

    std::vector<BookData> booksSorted = {
        {"House of Leaves", Genre::Mystery, 736},
        {"Interview with the Vampire", Genre::GothicFiction, 308},
        {"Legend of the Galactic Heroes: Dawn", Genre::SpaceOpera, 292},
        {"Memnoch the Devil", Genre::GothicFiction, 401},
        {"The Lesser Dead", Genre::GothicFiction, 357},
        {"The Resurrectionist: The Lost Work of Dr. Spencer Black", Genre::Mystery, 192},
        {"The Temple of the Golden Pavilion", Genre::Novel, 264},
        {"Those Across the River", Genre::HorrorFiction, 340},
        {"Uzumaki", Genre::HorrorFiction, 648},
        {"Vampire Hunter D Omnibus: Book One", Genre::Fiction, 640}
    };

    std::vector<BookData> booksReverseSorted = {
        {"Vampire Hunter D Omnibus: Book One", Genre::Fiction, 640},
        {"Uzumaki", Genre::HorrorFiction, 648},
        {"Those Across the River", Genre::HorrorFiction, 340},
        {"The Temple of the Golden Pavilion", Genre::Novel, 264},
        {"The Resurrectionist: The Lost Work of Dr. Spencer Black", Genre::Mystery, 192},
        {"The Lesser Dead", Genre::GothicFiction, 357},
        {"Memnoch the Devil", Genre::GothicFiction, 401},
        {"Legend of the Galactic Heroes: Dawn", Genre::SpaceOpera, 292},
        {"Interview with the Vampire", Genre::GothicFiction, 308},
        {"House of Leaves", Genre::Mystery, 736}
    };

    std::string firstItem = "The Temple of the Golden Pavilion";
    std::string lastItem = "The Resurrectionist: The Lost Work of Dr. Spencer Black";
    std::string notInDatabase = "hello";

    //Serialize data
    serializeData(books, "books.csv");
    serializeData(booksSorted, "booksSorted.csv");

    //Deserialize data
    std::vector<BookData> deserializedBooks = deserializeData("books.csv");


    /*
    //Display deserialized data
    for (const auto& book : deserializedBooks) {
        std::cout << "Title: " << book.title << ", Genre: " << static_cast<int>(book.genre) << ", Page count: " << book.pageCount << std::endl;
    }*/
    
    std::cout << "In case of the item being the first in the data base: " << std::endl;
    analyzeSpeed(deserializedBooks, firstItem);
    std::cout << std::endl;
    std::cout << "In case of the item being the last in the data base: " << std::endl;
    analyzeSpeed(deserializedBooks, lastItem);
    std::cout << std::endl;
    std::cout << "In case of the item not existing in the data base: " << std::endl;
    analyzeSpeed(deserializedBooks, notInDatabase);
    std::cout << std::endl;
    std::cout << "In case of the item being the first in the data base which is sorted: " << std::endl;
    analyzeSpeed(booksSorted, firstItem);
    std::cout << std::endl;
    std::cout << "In case of the item being the last in the data base which is sorted: " << std::endl;
    analyzeSpeed(booksSorted, lastItem);
    std::cout << std::endl;
    std::cout << "In case of the item being the first in the data base which is reverse sorted: " << std::endl;
    analyzeSpeed(booksReverseSorted, lastItem);

    return 0;
}


