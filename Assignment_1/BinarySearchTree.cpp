#include "Serialization.h"
#include <vector>

//Binary tree node
struct TreeNode {
    BookData data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const BookData& book) :data(book), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {

};