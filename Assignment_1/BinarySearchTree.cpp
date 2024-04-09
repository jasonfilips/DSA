#include "Serialization.h"

//Binary tree node
struct TreeNode {
    BookData book;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const BookData& book) :book(book), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, const BookData& book);
    bool searchNode(TreeNode* node, const std::string& searchItem) const; //adding const at the end to not modify any member variables of the class
    void createTree(const std::vector<BookData>& books);
    void deleteTree(TreeNode* node);

public:
    BinarySearchTree(const std::vector<BookData>& books);
    ~BinarySearchTree();

    void insert(const BookData& book);
    void create(const std::vector<BookData>& books);
    bool search(const std::string& searchItem) const;
};

//Constructor
BinarySearchTree::BinarySearchTree(const std::vector<BookData>& books) : root(nullptr) {
    create(books);
}

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

//Public function to insert a new node into the tree
void BinarySearchTree::insert(const BookData& book) {
    root = insertNode(root, book);
}

//Private recursive function to insert a node into the tree
TreeNode* BinarySearchTree::insertNode(TreeNode* node, const BookData& book) {
    if (node == nullptr) {
        return new TreeNode(book);
    }

    if (book.title < node->book.title) {
        node->left = insertNode(node->left, book);
    }
    else {
        node->right = insertNode(node->right, book);
    }

    return node;
}

//Public function to search for a title 
bool BinarySearchTree::search(const std::string& searchItem) const {
    return searchNode(root, searchItem);
}


bool BinarySearchTree::searchNode(TreeNode* node, const std::string& searchItem) const {
    if (node == nullptr) {
        return false;
    }

    if (node->book.title == searchItem) {
        return true;
    }
    else if (searchItem < node->book.title) {
        return searchNode(node->left, searchItem);
    }
    else {
        return searchNode(node->right, searchItem);
    }
}

//Public function to create a tree
void BinarySearchTree::create(const std::vector<BookData>& books) {
    createTree(books);
}

//Function to create a tree from a books vector
void BinarySearchTree::createTree(const std::vector<BookData>& books) {
    for (const auto& book : books) {
        insert(book);
    }
}
