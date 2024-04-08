#pragma once

#ifndef BOOK_DATA_H
#define BOOK_DATA_H

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

//Function prototypes
void serializeData(const std::vector<BookData>& books, const std::string& filePath);
std::vector<BookData> deserializeData(const std::string& filePath);

#endif