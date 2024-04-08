#include "Serialization.cpp"
#include <chrono>

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