#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;
    int size;

    Node* getNodeAt(int index) const;

public:
    LinkedList();
    ~LinkedList();

    void add(const T& element);              // Add element at the end
    void addAt(int index, const T& element); // Add element at a specific position
    T remove(int index);                     // Remove element at a specific position
    T& get(int index);                       // Get element (non-const reference)
    const T& get(int index) const;           // Get element (const reference)
    int getSize() const;                     // Get the number of elements
    bool isEmpty() const;                    // Check if the list is empty
    void display() const;                    // Display all elements
};

// Constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    while (!isEmpty()) {
        remove(0);
    }
}

// Add element at the end
template <typename T>
void LinkedList<T>::add(const T& element) {
    if (isEmpty()) {
        head = new Node(element);
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(element);
    }
    size++;
}

// Add element at a specific position
template <typename T>
void LinkedList<T>::addAt(int index, const T& element) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of bounds");
    }

    if (index == 0) {
        head = new Node(element, head);
    } else {
        Node* previous = getNodeAt(index - 1);
        previous->next = new Node(element, previous->next);
    }
    size++;
}

// Remove element at a specific position
template <typename T>
T LinkedList<T>::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }

    Node* nodeToRemove;
    T removedData;

    if (index == 0) {
        nodeToRemove = head;
        head = head->next;
    } else {
        Node* previous = getNodeAt(index - 1);
        nodeToRemove = previous->next;
        previous->next = nodeToRemove->next;
    }

    removedData = nodeToRemove->data;
    delete nodeToRemove;
    size--;

    return removedData;
}

// Get element (non-const reference)
template <typename T>
T& LinkedList<T>::get(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return getNodeAt(index)->data;
}

// Get element (const reference)
template <typename T>
const T& LinkedList<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return getNodeAt(index)->data;
}

// Get the node at a specific position
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::getNodeAt(int index) const {
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

// Get the number of elements
template <typename T>
int LinkedList<T>::getSize() const {
    return size;
}

// Check if the list is empty
template <typename T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

// Display all elements
template <typename T>
void LinkedList<T>::display() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

#endif // LINKEDLIST_H
