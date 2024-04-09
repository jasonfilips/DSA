#include "Serialization.h"
#include "LinearSearch.h"
#include "BinaryTreeSearch.h"
#include "BinarySearch.h"
#include <vector>
#include <chrono>
#include <string_view>
#include <span>


template<typename Func>
std::chrono::duration<double> analyzeFunc(Func f)
{
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 100000; i++) {
        f();
    }
    auto end = std::chrono::steady_clock::now();
    return end - start;
}

bool analyzeSpeed(std::span<BookData> books, std::string_view searchItem) {
    std::cout << "Testing the speed of the algorithms" << std::endl;
    std::chrono::duration<double> linearSearchTotalTime;
    std::chrono::duration<double> binaryTreeSearchTotalTime;
    std::chrono::duration<double> binarySearchTotalTime;
    std::chrono::duration<double> binaryTreeCreationTime;


    bool binaryTreeSearchFound = false;
    bool binarySearchFound = false;
    bool linearSearchFound = false;

    BinaryTreeSearch bst(books);


    linearSearchTotalTime = analyzeFunc([&]()
        {
            return linearSearch(books, searchItem);
        });

    binaryTreeSearchTotalTime = analyzeFunc([&]()
        {
            return bst.search(searchItem);
        });

    binarySearchTotalTime = analyzeFunc([&]()
        {
            return binarySearch(books, searchItem);
        });
    binaryTreeCreationTime = analyzeFunc([&]()
        {
            BinaryTreeSearch bst2(books);
            return;
        });



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

    std::string_view firstItem = "The Temple of the Golden Pavilion";
    std::string_view lastItem = "The Resurrectionist: The Lost Work of Dr. Spencer Black";
    std::string_view notInDatabase = "hello";

    std::string_view firstItemSorted = "House of Leaves";
    std::string_view lastItemSorted = "Vampire Hunter D Omnibus: Book One";


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
    analyzeSpeed(booksSorted, firstItemSorted);
    std::cout << std::endl;
    std::cout << "In case of the item being the last in the data base which is sorted: " << std::endl;
    analyzeSpeed(booksSorted, lastItemSorted);
    std::cout << std::endl;
    std::cout << "In case of the item being the first in the data base which is reverse sorted: " << std::endl;
    analyzeSpeed(booksReverseSorted, lastItemSorted);

    return 0;
}


