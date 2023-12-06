#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* first;
    Node* last;
};

void enqueue(Queue* queue, int value) {
    Node* newNode = new Node{value, nullptr};
    if (queue->last != nullptr) queue->last->next = newNode;
    queue->last = newNode;
    if (queue->first == nullptr) queue->first = newNode;
}

int dequeue(Queue* queue) {
    if (queue->first == nullptr) return -1;
    Node* temp = queue->first;
    int value = temp->data;
    queue->first = queue->first->next;
    delete temp;
    if (queue->first == nullptr) queue->last = nullptr;
    return value;
}

bool isEmpty(Queue* queue) {
    return queue->first == nullptr;
}
void testQueue() {
    Queue queue{nullptr, nullptr};

    assert(isEmpty(&queue));

    enqueue(&queue, 10);
    assert(!isEmpty(&queue));

    enqueue(&queue, 20);
    assert(!isEmpty(&queue));

    int value = dequeue(&queue);
    assert(value == 10);
    assert(!isEmpty(&queue));

    value = dequeue(&queue);
    assert(value == 20);
    assert(isEmpty(&queue));

    std::cout << "Queue tests passed.\n";
}

int main() {
    testQueue();
    return 0;
}
