#pragma once

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../Assignment_1/Serialization.h"
#include <vector>
#include <span>

struct ListNode {
    BookData book;
    ListNode* nextNode;

    ListNode(BookData&& book);
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

#endif