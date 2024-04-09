#include "Serialization.h"
#include <span>

//Binary tree node
struct TreeNode {
    BookData book;
    TreeNode* left;
    TreeNode* right;

    TreeNode(BookData&& book) :book(std::move(book)), left(nullptr), right(nullptr) {}
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

//Constructor
BinaryTreeSearch::BinaryTreeSearch(std::span<BookData> books) : root(nullptr) {
    create(books);
}

//Destructor
BinaryTreeSearch::~BinaryTreeSearch() {
    deleteTree(root);
}

//Recursive destructor for the following nodes
void BinaryTreeSearch::deleteTree(TreeNode* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

//Public function to insert a new node into the tree
void BinaryTreeSearch::insert(BookData&& book) {
    root = insertNode(root, std::move(book));
}

//Private recursive function to insert a node into the tree
TreeNode* BinaryTreeSearch::insertNode(TreeNode* node, BookData&& book) {
    if (node == nullptr) {
        return new TreeNode(std::move(book));
    }

    if (book.title < node->book.title) {
        node->left = insertNode(node->left, std::move(book));
    }
    else {
        node->right = insertNode(node->right, std::move(book));
    }

    return node;
}

//Public function to search for a title 
bool BinaryTreeSearch::search(std::string_view searchItem) const {
    return searchNode(root, searchItem);
}


bool BinaryTreeSearch::searchNode(TreeNode* node, std::string_view searchItem) const {
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
void BinaryTreeSearch::create(std::span<BookData> books) {
    createTree(books);
}

//Function to create a tree from a books vector
void BinaryTreeSearch::createTree(std::span<BookData> books) {
    for (auto& book : books) {
        insert(std::move(book));
    }
}
