#ifndef TEST_CPP3_LINKEDLIST_H
#define TEST_CPP3_LINKEDLIST_H


template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class Iterator {
private:
    Node<T>* current;

public:
    Iterator(Node<T>* node) : current(node) {}
    bool isEnd() const;
    T& operator*() const;
    void operator++();
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    bool isEmpty() const;
    void clear();
    int find(const T& value) const;
    void removeAt(int position);
    void insertAtBeginning(const T& value);
    Iterator<T> begin() const;
};

#include "LinkedList.tpp"


#endif