// Assignment_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

//Enum representing different book genres
enum class Genre {
    SpaceOpera,
    Fiction,
    Mystery,
    Novel,
    NonFiction
};

//Struct to represent information about a book
struct BookData {
    std::string title;
    Genre genre;
    int pageCount;
};

//Serializing data into a CSV file
//Using & to not copy the data, but use a refference
//Using const to not modify the data
void serializeData(const std::vector<BookData>& books, const std::string& filePath) {
    //created a new variable using the ofstream constructor
    std::ofstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    //Adding the header
    file << "Title,Genre,PageCount\n";

    //Adding each book's data
    for (const auto& book : books) {
        file << book.title << "," << static_cast<int>(book.genre) << "," << book.pageCount << "\n";
    }
}


int main()
{
   //Example
    std::vector<BookData> books = {
        {"The Temple of the Golden Pavilion", Genre::Novel, 264},
        {"Legend of the Galactic Heroes: Dawn", Genre::SpaceOpera, 292},
        {"House of Leaves", Genre::Mystery, 736}
    };

    //Serialize data
    serializeData(books, "books.csv");
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
