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

    file.close();
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