#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

struct LinkedList {
    Node* first;
    Node* last;
    int size;
};

Node* insertAfter(LinkedList* list, Node* node, int value) {
    Node* newNode = new Node{value, node, (node != nullptr) ? node->next : list->first};
    if (node == nullptr) list->first = newNode;
    if (node != nullptr) node->next = newNode;
    if (newNode->next != nullptr) newNode->next->prev = newNode;
    if (node == list->last) list->last = newNode;
    list->size++;
    return newNode;
}

Node* insertBefore(LinkedList* list, Node* node, int value) {
    Node* newNode = new Node{value, (node != nullptr) ? node->prev : list->last, node};
    if (node != nullptr) node->prev = newNode;
    if (newNode->prev != nullptr) newNode->prev->next = newNode;
    if (node == nullptr) list->last = newNode;
    if (node == list->first) list->first = newNode;
    list->size++;
    return newNode;
}

Node* find(LinkedList* list, int value) {
    Node* current = list->first;
    while (current != nullptr && current->data != value) current = current->next;
    return current;
}

void remove(LinkedList* list, Node* node) {
    if (node == nullptr) return;
    if (node->prev != nullptr) node->prev->next = node->next;
    else list->first = node->next;
    if (node->next != nullptr) node->next->prev = node->prev;
    else list->last = node->prev;
    delete node;
    list->size--;
}

void assertNoCycles(LinkedList* list) {
    int count = 0;
    Node* current = list->first;
    while (current != nullptr && count++ <= list->size * 2) current = current->next;
    assert(count <= list->size * 2);
}

// Test function for the doubly linked list
void testDoublyLinkedList() {
    LinkedList list{nullptr, nullptr, 0};

    Node* node1 = insertAfter(&list, nullptr, 10);
    Node* node2 = insertAfter(&list, node1, 20);
    Node* node3 = insertBefore(&list, node1, 5);
    Node* node4 = insertBefore(&list, node2, 15);

    Node* foundNode = find(&list, 5);

    remove(&list, node1);
    remove(&list, node2);

    assertNoCycles(&list);

    std::cout << "Doubly linked list tests passed.\n";
}

int main() {
    testDoublyLinkedList();
    return 0;
}
