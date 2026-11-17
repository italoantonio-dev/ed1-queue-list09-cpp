#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <cstddef>
#include <iostream>
#include <stdexcept>

#include "Queue.h"

template <typename T>
class ArrayQueue : public Queue<T> {
private:
    T* items;
    std::size_t capacity_;
    std::size_t count;

public:
    explicit ArrayQueue(std::size_t capacity)
        : items(new T[capacity]), capacity_(capacity), count(0) {}

    ~ArrayQueue() override { delete[] items; }

    ArrayQueue(const ArrayQueue&) = delete;
    ArrayQueue& operator=(const ArrayQueue&) = delete;

    void push(const T& value) override {
        if (isFull()) {
            throw std::overflow_error("fila cheia");
        }
        items[count] = value;
        ++count;
    }

    T pop() override {
        if (isEmpty()) {
            throw std::underflow_error(" fila vazia");
        }
        T front = items[0];
        for (std::size_t i = 1; i < count; ++i) {
            items[i - 1] = items[i];
        }
        --count;
        return front;
    }

    T popBack() {
        if (isEmpty()) {
            throw std::underflow_error(" fila vazia");
        }
        --count;
        return items[count];
    }

    const T& peek() const override {
        if (isEmpty()) {
            throw std::underflow_error("ArrayQueue: fila vazia");
        }
        return items[0];
    }

    bool isEmpty() const override { return count == 0; }
    bool isFull() const { return count == capacity_; }
    std::size_t size() const override { return count; }
    std::size_t capacity() const { return capacity_; }

    void print(std::ostream& os) const override {
        for (std::size_t i = 0; i < count; ++i) {
            if (i > 0) os << ' ';
            os << items[i];
        }
    }
};

#endif
