#include <iostream>
#include <sstream>
#include <string>

#include "LinkedQueue.h"

namespace {

void mergeTwoQueues(LinkedQueue<int>& a, LinkedQueue<int>& b, LinkedQueue<int>& result) {
    while (!a.isEmpty() && !b.isEmpty()) {
        if (a.peek() <= b.peek()) {
            a.transferFront(result);
        } else {
            b.transferFront(result);
        }
    }
    while (!a.isEmpty()) {
        a.transferFront(result);
    }
    while (!b.isEmpty()) {
        b.transferFront(result);
    }
}

void fillFromLine(LinkedQueue<int>& queue, const std::string& line) {
    std::istringstream iss(line);
    int x;
    while (iss >> x) {
        queue.push(x);
    }
}

}

void runExer05() {
    std::string lineA, lineB;
    std::getline(std::cin, lineA);
    std::getline(std::cin, lineB);

    LinkedQueue<int> a, b, result;
    fillFromLine(a, lineA);
    fillFromLine(b, lineB);

    mergeTwoQueues(a, b, result);

    result.print(std::cout);
    std::cout << '\n';
}
