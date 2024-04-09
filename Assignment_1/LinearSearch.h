#pragma once

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Serialization.h"

struct BookData;
enum class Genre;
struct TreeNode;

struct TreeNode {
    BookData data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const BookData& book) : data(book), left(nullptr), right(nullptr) {}
};

void algorithmExample();
bool LinearSearch(const std::vector<BookData>& books, std::string& searchItem);

#endif