#pragma once

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "Serialization.h"

struct TreeNode {
    BookData book;
    TreeNode* left;
    TreeNode* right;

    TreeNode(BookData&& book);
};

class BinaryTreeSearch {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, BookData&& book);
    bool searchNode(TreeNode* node, std::string_view searchItem) const;
    void createTree(std::span<BookData> books);
    void deleteTree(TreeNode* node);

public:
    BinaryTreeSearch(std::span<BookData> books);
    ~BinaryTreeSearch();

    void insert(BookData&& book);
    void create(std::span<BookData> books);
    bool search(std::string_view searchItem) const;
};

#endif