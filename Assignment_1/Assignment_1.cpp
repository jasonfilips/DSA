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

//Deserializing data from a CSV file
std::vector<BookData> deserializeData(const std::string& filePath) {
    std::vector<BookData> books;
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return books;
    }

    //Skipping the first line by reading and not storing it
    std::string line;
    std::getline(file, line);

    //Reading each line and adding data to books
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string title;
        int genre;
        int pageCount;

        if (std::getline(iss, title, ',') &&
            iss >> genre && // reads the int value untill encounters a non int value
            iss.ignore() && // Ignore the comma
            iss >> pageCount) {
            BookData book;
            book.title = title;
            book.genre = static_cast<Genre>(genre);
            book.pageCount = pageCount;
            books.push_back(book);
        }
    }

    file.close();
    return books;
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

    //Deserialize data
    std::vector<BookData> desirializedBooks = deserializeData("books.csv");

    //Display deserialized data
    for (const auto& book : desirializedBooks) {
        std::cout << "Title: " << book.title << ", Genre: " << static_cast<int>(book.genre) << ", Page count: " << book.pageCount << std::endl;
    }

    return 0;
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
