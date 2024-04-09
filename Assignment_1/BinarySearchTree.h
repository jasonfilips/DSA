#pragma once

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "Serialization.h"
#include <vector>

struct TreeNode;

struct TreeNode {
	BookData data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(const BookData& book) : data(book), left(nullptr), right(nullptr) {}
};

#endif