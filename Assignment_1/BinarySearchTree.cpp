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
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, const BookData& book);
    bool searchNode(TreeNode* node, const std::string& searchItem) const; //adding const at the end to not modify any member variables of the class
    void deleteTree(TreeNode* node);

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree();

    void insert(const BookData& book);
    bool search(const std::string& searchItem) const;
};

//Destructor
BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

//Recursive destructor for the following nodes
void BinarySearchTree::deleteTree(TreeNode* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

