#include <iostream>
#include <sstream>
#include <string>

#include "LinkedQueue.h"

namespace {

void splitEvenOdd(LinkedQueue<int>& source, LinkedQueue<int>& evens, LinkedQueue<int>& odds) {
    while (!source.isEmpty()) {
        int value = source.pop();
        if (value % 2 == 0) {
            evens.push(value);
        } else {
            odds.push(value);
        }
    }
}

}

void runExer06() {
    std::string line;
    std::getline(std::cin, line);

    LinkedQueue<int> source, evens, odds;
    {
        std::istringstream iss(line);
        int x;
        while (iss >> x) {
            source.push(x);
        }
    }

    splitEvenOdd(source, evens, odds);

    evens.print(std::cout);
    std::cout << '\n';
    odds.print(std::cout);
    std::cout << '\n';
}
