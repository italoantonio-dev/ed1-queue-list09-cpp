#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include <iostream>

template <typename T>
class Queue {
public:
    virtual ~Queue() = default;

    virtual void push(const T& value) = 0;
    virtual T pop() = 0;
    virtual const T& peek() const = 0;
    virtual bool isEmpty() const = 0;
    virtual std::size_t size() const = 0;
    virtual void print(std::ostream& os) const = 0;
};

#endif
