#pragma once

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Serialization.h"

struct BookData;
enum class Genre;
struct TreeNode;

struct TreeNode {
    BookData book;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const BookData& book) : book(book), left(nullptr), right(nullptr) {}
};

void algorithmExample();
bool linearSearch(const std::vector<BookData>& books, std::string& searchItem);

#endif