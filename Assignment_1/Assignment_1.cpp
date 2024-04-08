#include "Serialization.cpp"
#include <chrono>

void algorithmExample() {
    for (int i = 0; i < 100000000; i++) {
        int result = i * i;
    }
}

void analyzeSpeed() {
    std::cout << "Testing the speed of the algorithm" << std::endl;
    auto start = std::chrono::steady_clock::now();
    //run the algorithm 10 times
    for (int i = 0; i < 10; i++) {
        algorithmExample();
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time to complete the algorithm " << duration.count() << " seconds" << std::endl;
}

int main()
{
    //Example
    std::vector<BookData> books = {
        {"The Temple of the Golden Pavilion", Genre::Novel, 264},
        {"Legend of the Galactic Heroes: Dawn", Genre::SpaceOpera, 292},
        {"House of Leaves", Genre::Mystery, 736}
    };

    analyzeSpeed();

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