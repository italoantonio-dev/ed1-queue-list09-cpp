#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>

#include "LinkedQueue.h"

namespace {

int countOccurrences(LinkedQueue<int>& queue, int target) {
    int occurrences = 0;
    const std::size_t n = queue.size();

    for (std::size_t i = 0; i < n; ++i) {
        if (queue.peek() == target) {
            ++occurrences;
        }
        queue.push(queue.pop());
    }
    return occurrences;
}

}

void runExer04() {
    std::string line;
    std::getline(std::cin, line);

    LinkedQueue<int> queue;
    {
        std::istringstream iss(line);
        int x;
        while (iss >> x) {
            queue.push(x);
        }
    }

    int target = 0;
    std::cin >> target;

    std::cout << countOccurrences(queue, target) << '\n';
}
