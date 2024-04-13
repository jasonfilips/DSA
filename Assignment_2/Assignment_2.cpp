//#include "LinkedList.h"
#include "../Assignment_1/Serialization.h"
#include <iostream>
#include <vector>

int main()
{
    std::string filepath = "../Assignment_1/books.csv";

    std::vector<BookData> books = deserializeData(filepath);
}
