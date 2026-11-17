#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

namespace {

class StackBasedQueue {
private:
    std::stack<int> in_stack;
    std::stack<int> out_stack;

    void refillOutStack() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
    }

public:
    void push(int x) { in_stack.push(x); }

    int pop() {
        refillOutStack();
        if (out_stack.empty()) {
            throw std::underflow_error("StackBasedQueue: fila vazia");
        }
        int value = out_stack.top();
        out_stack.pop();
        return value;
    }

    int peek() {
        refillOutStack();
        if (out_stack.empty()) {
            throw std::underflow_error("StackBasedQueue: fila vazia");
        }
        return out_stack.top();
    }

    bool isEmpty() const { return in_stack.empty() && out_stack.empty(); }
};

}

void runExer02() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);

    StackBasedQueue queue;
    bool first = true;
    int command;

    while (iss >> command) {
        if (command == -1 || command == -2) {
            try {
                int value = (command == -1) ? queue.pop() : queue.peek();
                if (!first) std::cout << ' ';
                std::cout << value;
                first = false;
            } catch (const std::underflow_error& e) {
                std::cerr << "Aviso: " << e.what() << " -- comando " << command << " ignorado\n";
            }
        } else {
            queue.push(command);
        }
    }
    std::cout << '\n';
}
