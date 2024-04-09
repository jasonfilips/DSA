#pragma once

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "Serialization.h"

struct TreeNode {
    BookData book;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const BookData& book);
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, const BookData& book);
    bool searchNode(TreeNode* node, const std::string& searchItem) const;
    void createTree(const std::vector<BookData>& books);
    void deleteTree(TreeNode* node);
public:
    BinarySearchTree(const std::vector<BookData>& books);
    ~BinarySearchTree();

    void insert(const BookData& book);
    void create(const std::vector<BookData>& books);
    bool search(const std::string& searchItem) const;
};

#endif