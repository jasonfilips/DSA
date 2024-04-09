#include "../Assignment_1/Serialization.h"
#include <vector>

struct ListNode {
    BookData book;
    ListNode* nextNode;

    ListNode(const BookData& book);
};


class LinkedList {
private:
    ListNode* rootNode;

    ListNode* insertNode(ListNode* node, const BookData& book);
    ListNode* insertAfterNode(LinkedList* list, ListNode* node, const BookData& book);
    void removeAfter(LinkedList* list, ListNode* node);
    std::vector<ListNode*> searchNodeByTitle(ListNode* node, const std::string& searchItem, std::vector<ListNode*>& foundNodes) const;
    void createList(const std::vector<BookData>& books);
    void deleteList(ListNode* node);
    void assertNoCycles(LinkedList* list, ListNode* node);

public:
    LinkedList(const std::vector<BookData>& books);
    ~LinkedList();

    void insert(const BookData& book);
    ListNode* insertAfter(LinkedList* list, ListNode* node, const BookData& book);
    void remove(LinkedList* list, ListNode* node);
    std::vector<ListNode*> search(const std::string& searchItem, std::vector<ListNode*>& foundNodes) const;
    void create(const std::vector<BookData>& books);
};

//Constructor
LinkedList::LinkedList(const std::vector<BookData>& books) : rootNode(nullptr) {
    create(books);
}

//Destructor
LinkedList::~LinkedList() {
    deleteList(rootNode);
}

//Recursive destructor to delete nodes
void LinkedList::deleteList(ListNode* node) {
    if (node) {
        deleteList(node->nextNode);
        delete node;
    }
}

//Public function to insert a new node into the list
void LinkedList::insert(const BookData& book) {
    rootNode = insertNode(rootNode, book);
}

//Private recursive function to insert a node into the tree
ListNode* LinkedList::insertNode(ListNode* node, const BookData& book) {
    if (node == nullptr) {
        return new ListNode(book);
    }
    else {
        node->nextNode = insertNode(node->nextNode, book);
    }

    return node;
}

//Public function to insert a node after a specified node
ListNode* LinkedList::insertAfter(LinkedList* list, ListNode* node, const BookData& book) {
    return insertAfterNode(list, node, book);
}

//Private function to insert a node after a specified node
ListNode* LinkedList::insertAfterNode(LinkedList* list, ListNode* node, const BookData& book) {
    ListNode* newNode = new ListNode(book);

    if (node == nullptr) {
        newNode->nextNode = list->rootNode;
        list->rootNode = newNode;
    }
    else {
        newNode->nextNode = node->nextNode;
        node->nextNode = newNode;
    }

    return newNode;
}


//Public function to search for a node by the title and returns the node and the one before it
std::vector<ListNode*> LinkedList::search(const std::string& searchItem, std::vector<ListNode*>& foundNodes) const {
    return searchNodeByTitle(rootNode, searchItem, foundNodes);
}

//Private function to search for a node by the title and returns a vector which contains the node and the one before it
std::vector<ListNode*> LinkedList::searchNodeByTitle(ListNode* node, const std::string& searchItem, std::vector<ListNode*>& foundNodes) const {

    if (node == nullptr) {
        return foundNodes;
    }

    if (node->book.title == searchItem) {
        foundNodes.push_back(node);
    }
    else {
        foundNodes[0] = node;
        return searchNodeByTitle(node->nextNode, searchItem, foundNodes);
    }
}

//Public function to create a linked list
void LinkedList::create(const std::vector<BookData>& books) {
    createList(books);
}

//Private function to create a linked list
void LinkedList::createList(const std::vector<BookData>& books) {
    for (const auto& book : books) {
        insert(book);
    }
}


