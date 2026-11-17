#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <cstddef>
#include <iostream>
#include <stdexcept>

#include "Queue.h"

template <typename T>
class LinkedQueue : public Queue<T> {
private:
    struct Node {
        T data;
        Node* next;
        explicit Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    std::size_t count;

public:
    LinkedQueue() : head(nullptr), tail(nullptr), count(0) {}

    ~LinkedQueue() override { clear(); }

    LinkedQueue(const LinkedQueue&) = delete;
    LinkedQueue& operator=(const LinkedQueue&) = delete;

    void push(const T& value) override {
        Node* node = new Node(value);
        if (tail == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
        ++count;
    }

    T pop() override {
        if (isEmpty()) {
            throw std::underflow_error("LinkedQueue: fila vazia");
        }
        Node* node = head;
        T value = node->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete node;
        --count;
        return value;
    }

    const T& peek() const override {
        if (isEmpty()) {
            throw std::underflow_error("LinkedQueue: fila vazia");
        }
        return head->data;
    }

    void transferFront(LinkedQueue& dest) {
        if (isEmpty()) {
            throw std::underflow_error("LinkedQueue: fila vazia");
        }
        Node* node = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        --count;

        node->next = nullptr;
        if (dest.tail == nullptr) {
            dest.head = node;
        } else {
            dest.tail->next = node;
        }
        dest.tail = node;
        ++dest.count;
    }

    void clear() {
        while (head != nullptr) {
            Node* node = head;
            head = head->next;
            delete node;
        }
        tail = nullptr;
        count = 0;
    }

    bool isEmpty() const override { return count == 0; }
    std::size_t size() const override { return count; }

    void print(std::ostream& os) const override {
        for (const Node* cur = head; cur != nullptr; cur = cur->next) {
            if (cur != head) os << ' ';
            os << cur->data;
        }
    }
};

#endif
