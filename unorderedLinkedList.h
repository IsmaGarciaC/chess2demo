#pragma once
#include <iostream>
#include <cassert>

template <class Type>
class nodeType {
public:
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class unorderedLinkedList {
public:
    unorderedLinkedList();
    ~unorderedLinkedList();
    void initializeList();
    bool isEmptyList() const;
    int length() const;
    void destroyList();
    void print() const;
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);

    // Iterator support
    class iterator {
    public:
        iterator(nodeType<Type>* ptr = nullptr) : current(ptr) {}
        Type& operator*() { return current->info; }
        iterator& operator++() { current = current->link; return *this; }
        bool operator!=(const iterator& rhs) const { return current != rhs.current; }

    private:
        nodeType<Type>* current;
    };

    iterator begin() { return iterator(first); }
    iterator end() { return iterator(nullptr); }

private:
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last;

    void copyList(const unorderedLinkedList<Type>& otherList);
};

template <class Type>
unorderedLinkedList<Type>::unorderedLinkedList() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
unorderedLinkedList<Type>::~unorderedLinkedList() {
    destroyList();
}

template <class Type>
void unorderedLinkedList<Type>::initializeList() {
    destroyList();
}

template <class Type>
bool unorderedLinkedList<Type>::isEmptyList() const {
    return (first == nullptr);
}

template <class Type>
int unorderedLinkedList<Type>::length() const {
    return count;
}

template <class Type>
void unorderedLinkedList<Type>::destroyList() {
    nodeType<Type> *temp;
    while (first != nullptr) {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem) {
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = first;
    first = newNode;
    count++;

    if (last == nullptr)
        last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem) {
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = nullptr;

    if (first == nullptr) {
        first = newNode;
        last = newNode;
        count++;
    } else {
        last->link = newNode;
        last = newNode;
        count++;
    }
}

template <class Type>
void unorderedLinkedList<Type>::print() const {
    nodeType<Type> *current;
    current = first;
    while (current != nullptr) {
        std::cout << current->info << " ";
        current = current->link;
    }
}
