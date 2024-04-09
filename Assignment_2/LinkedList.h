#pragma once

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../Assignment_1/Serialization.h"

#include "../Assignment_1/Serialization.h"

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

#endif