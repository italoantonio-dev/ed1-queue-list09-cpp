#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <cstddef>
#include <stdexcept>

#include "Stack.h"

template <typename T>
class ArrayStack : public Stack<T> {
private:
    T* items;
    std::size_t capacity_;
    std::size_t count;

public:
    explicit ArrayStack(std::size_t capacity)
        : items(new T[capacity]), capacity_(capacity), count(0) {}

    ~ArrayStack() override { delete[] items; }

    ArrayStack(const ArrayStack&) = delete;
    ArrayStack& operator=(const ArrayStack&) = delete;

    void push(const T& value) override {
        if (count == capacity_) {
            throw std::overflow_error("ArrayStack: pilha cheia");
        }
        items[count] = value;
        ++count;
    }

    T pop() override {
        if (isEmpty()) {
            throw std::underflow_error("ArrayStack: pilha vazia");
        }
        --count;
        return items[count];
    }

    const T& peek() const override {
        if (isEmpty()) {
            throw std::underflow_error("ArrayStack: pilha vazia");
        }
        return items[count - 1];
    }

    bool isEmpty() const override { return count == 0; }
    std::size_t size() const override { return count; }
};

#endif
