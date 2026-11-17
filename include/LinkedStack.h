#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <cstddef>
#include <stdexcept>

#include "Stack.h"

template <typename T>
class LinkedStack : public Stack<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value, Node* nxt) : data(value), next(nxt) {}
    };

    Node* topNode;
    std::size_t count;

public:
    LinkedStack() : topNode(nullptr), count(0) {}

    ~LinkedStack() override {
        while (topNode != nullptr) {
            Node* node = topNode;
            topNode = topNode->next;
            delete node;
        }
    }

    LinkedStack(const LinkedStack&) = delete;
    LinkedStack& operator=(const LinkedStack&) = delete;

    void push(const T& value) override {
        topNode = new Node(value, topNode);
        ++count;
    }

    T pop() override {
        if (isEmpty()) {
            throw std::underflow_error("LinkedStack: pilha vazia");
        }
        Node* node = topNode;
        T value = node->data;
        topNode = topNode->next;
        delete node;
        --count;
        return value;
    }

    const T& peek() const override {
        if (isEmpty()) {
            throw std::underflow_error("LinkedStack: pilha vazia");
        }
        return topNode->data;
    }

    bool isEmpty() const override { return count == 0; }
    std::size_t size() const override { return count; }
};

#endif
