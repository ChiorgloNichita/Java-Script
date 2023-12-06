#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* first;
    Node* last;
    int size;
};

struct FindNodeResult {
    Node* current;
    Node* previous;
};

Node* insertAfter(LinkedList* list, Node* node, int value) {
    Node* newNode = new Node{value, (node == nullptr) ? list->first : node->next};
    if (node == nullptr) list->first = newNode;
    if (node == list->last) list->last = newNode;
    if (node != nullptr) node->next = newNode;
    list->size++;
    return newNode;
}

FindNodeResult find(LinkedList* list, int value) {
    FindNodeResult result{list->first, nullptr};
    while (result.current != nullptr && result.current->data != value)
        result.previous = result.current, result.current = result.current->next;
    return result;
}

void removeAfter(LinkedList* list, Node* node) {
    if (node == nullptr) {
        Node* temp = list->first;
        list->first = list->first->next;
        delete temp;
        if (list->first == nullptr) list->last = nullptr;
    } else if (node->next != nullptr) {
        Node* temp = node->next;
        node->next = node->next->next;
        delete temp;
        if (node->next == nullptr) list->last = node;
    }
    list->size--;
}

void assertNoCycles(LinkedList* list) {
    int count = 0;
    Node* current = list->first;
    while (current != nullptr && count++ <= list->size)
        current = current->next;
    assert(count <= list->size);
}

// Test function for the singly linked list
void testSinglyLinkedList() {
    LinkedList list{nullptr, nullptr, 0};

    Node* node1 = insertAfter(&list, nullptr, 10);
    Node* node2 = insertAfter(&list, node1, 20);
    Node* node3 = insertAfter(&list, node1, 15);

    FindNodeResult result = find(&list, 20);
    assert(result.current == node2 && result.previous == node1);

    removeAfter(&list, node1);
    removeAfter(&list, nullptr);

    assertNoCycles(&list);

    std::cout << "Singly linked list tests passed.\n";
}

int main() {
    testSinglyLinkedList();
    return 0;
}
