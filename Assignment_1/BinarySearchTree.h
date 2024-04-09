#pragma once

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "Serialization.h"
#include <vector>

struct TreeNode;

struct TreeNode {
	BookData book;
	TreeNode* left;
	TreeNode* right;

	TreeNode(const BookData& book) : book(book), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, const BookData& book);
    bool searchNode(TreeNode* node, const std::string& searchItem) const;
    void deleteTree(TreeNode* node);
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(const BookData& book);
    bool search(const std::string& searchItem) const;
};

#endif