#include "../Assignment_1/Serialization.h"
#include <vector>
#include <span>

struct ListNode {
    BookData book;
    ListNode* nextNode;

    ListNode(BookData&& book) :book(std::move(book)), nextNode(nullptr){};
};


class LinkedList {
private:
    ListNode* rootNode;

    ListNode* insertNode(ListNode* node, BookData&& book);
    ListNode* insertAfterNode(LinkedList* list, ListNode* node, BookData&& book);
    //void removeAfter(LinkedList* list, ListNode* node);
    std::vector<ListNode*> searchNodeByTitle(ListNode* node, std::string_view searchItem, std::vector<ListNode*>& foundNodes) const;
    void createList(std::span<BookData> books);
    void deleteList(ListNode* node);
    //void assertNoCycles(LinkedList* list, ListNode* node);

public:
    LinkedList(std::span<BookData> books);
    ~LinkedList();

    void insert(BookData&& book);
    ListNode* insertAfter(LinkedList* list, ListNode* node, BookData&& book);
    //void remove(LinkedList* list, ListNode* node);
    std::vector<ListNode*> search(std::string_view searchItem, std::vector<ListNode*>& foundNodes) const;
    void create(std::span<BookData> books);
};

//Constructor
LinkedList::LinkedList(std::span<BookData> books) : rootNode(nullptr) {
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
void LinkedList::insert(BookData&& book) {
    rootNode = insertNode(rootNode, std::move(book));
}

//Private recursive function to insert a node into the tree
ListNode* LinkedList::insertNode(ListNode* node, BookData&& book) {
    if (node == nullptr) {
        return new ListNode(std::move(book));
    }
    else {
        node->nextNode = insertNode(node->nextNode, std::move(book));
    }

    return node;
}

//Public function to insert a node after a specified node
ListNode* LinkedList::insertAfter(LinkedList* list, ListNode* node, BookData&& book) {
    return insertAfterNode(list, node, std::move(book));
}

//Private function to insert a node after a specified node
ListNode* LinkedList::insertAfterNode(LinkedList* list, ListNode* node, BookData&& book) {
    ListNode* newNode = new ListNode(std::move(book));

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
std::vector<ListNode*> LinkedList::search(std::string_view searchItem, std::vector<ListNode*>& foundNodes) const {
    return searchNodeByTitle(rootNode, searchItem, foundNodes);
}

//Private function to search for a node by the title and returns a vector which contains the node and the one before it
std::vector<ListNode*> LinkedList::searchNodeByTitle(ListNode* node, std::string_view searchItem, std::vector<ListNode*>& foundNodes) const {

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
    return foundNodes;
}

//Public function to create a linked list
void LinkedList::create(std::span<BookData> books) {
    createList(books);
}

//Private function to create a linked list
void LinkedList::createList(std::span<BookData> books) {
    for (auto& book : books) {
        insert(std::move(book));
    }
}


