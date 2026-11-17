#include <cctype>
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

void runExer03() {
    std::string line;
    std::getline(std::cin, line);

    ArrayQueue<int> deque(countInts(line));
    {
        std::istringstream iss(line);
        int x;
        while (iss >> x) {
            deque.push(x);
        }
    }

    std::string ops;
    std::getline(std::cin, ops);

    bool first = true;
    for (char raw : ops) {
        if (std::isspace(static_cast<unsigned char>(raw))) {
            continue;
        }
        char op = static_cast<char>(std::toupper(static_cast<unsigned char>(raw)));
        if (op != 'F' && op != 'B') {
            std::cerr << "Aviso: operação '" << raw << "' desconhecida (use F ou B)\n";
            continue;
        }

        try {
            int removed = (op == 'F') ? deque.pop() : deque.popBack();
            if (!first) std::cout << ' ';
            std::cout << removed;
            first = false;
        } catch (const std::underflow_error& e) {
            std::cerr << "Aviso: " << e.what() << " -- operação " << op << " ignorada\n";
        }
    }
    std::cout << '\n';
}
