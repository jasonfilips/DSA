#pragma once

#ifndef BINARY_H
#define BINARY_H

#include "Serialization.h"
#include <span>

bool binarySearch(std::span<BookData> books, std::string_view searchItem);

#endif