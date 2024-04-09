#pragma once

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Serialization.h"

struct BookData;
enum class Genre;

void algorithmExample();
bool linearSearch(const std::vector<BookData>& books, std::string& searchItem);

#endif