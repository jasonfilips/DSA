#pragma once

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Serialization.h"
#include <span>

struct BookData;
enum class Genre;

void algorithmExample();
bool linearSearch(std::span<BookData> books, std::string_view searchItem);

#endif