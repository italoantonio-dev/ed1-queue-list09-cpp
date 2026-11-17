#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "ArrayQueue.h"

namespace {

std::size_t countInts(const std::string& line) {
    std::istringstream iss(line);
    int x;
    std::size_t n = 0;
    while (iss >> x) {
        ++n;
    }
    return n;
}

}

void runExer01() {
    std::string line;
    std::getline(std::cin, line);

    ArrayQueue<int> queue(countInts(line));
    {
        std::istringstream iss(line);
        int x;
        while (iss >> x) {
            queue.push(x);
        }
    }

    int k = 0;
    if (!(std::cin >> k)) {
        k = 0;
    }

    bool first = true;
    for (int i = 0; i < k; ++i) {
        try {
            int removed = queue.pop();
            if (!first) std::cout << ' ';
            std::cout << removed;
            first = false;
        } catch (const std::underflow_error& e) {
            std::cerr << "Aviso: " << e.what() << " (restam " << (k - i) << " pop() sem efeito)\n";
            break;
        }
    }
    std::cout << '\n';

    queue.print(std::cout);
    std::cout << '\n';
}
