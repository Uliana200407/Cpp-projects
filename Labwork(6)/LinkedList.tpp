#include "LinkedList.h"
#include <iostream>

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template<typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
int LinkedList<T>::find(const T &value) const {
    int index = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

template<typename T>
void LinkedList<T>::removeAt(int position) {
    if (position < 0)
        return;

    if (position == 0) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node<T>* previous = nullptr;
    Node<T>* current = head;
    int index = 0;

    while (current != nullptr && index < position) {
        previous = current;
        current = current->next;
        index++;
    }

    if (current != nullptr) {
        previous->next = current->next;
        delete current;
    }
}

template<typename T>
void LinkedList<T>::insertAtBeginning(const T &value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
}

template<typename T>
Iterator<T> LinkedList<T>::begin() const {
    return Iterator<T>(head);
}


template<typename T>
bool Iterator<T>::isEnd() const  {
    return current == nullptr;
}

template<typename T>
T &Iterator<T>::operator*() const {
    return current->data;
}

template<typename T>
void Iterator<T>::operator++() {
    if (current != nullptr) {
        current = current->next;
    }
}

