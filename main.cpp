#include <iostream>
#include <limits>
#include <string>

void runExer01();
void runExer02();
void runExer03();
void runExer04();
void runExer05();
void runExer06();

namespace {

void printMenu() {
    std::cout << "=== ED1 - Lista 09: Filas FIFO ===\n"
              << "1 - Fila Estatica com Deslocamento Imediato\n"
              << "2 - Fila com Duas Pilhas (Amortized FIFO)\n"
              << "3 - Fila com Saida Dupla (Deque)\n"
              << "4 - Contagem Preservando Estado FIFO\n"
              << "5 - Intercalacao de Filas Ordenadas\n"
              << "6 - Particao Par/Impar Estavel\n"
              << "Escolha a questao (1-6): ";
}

bool runExercise(int number) {
    switch (number) {
        case 1: runExer01(); return true;
        case 2: runExer02(); return true;
        case 3: runExer03(); return true;
        case 4: runExer04(); return true;
        case 5: runExer05(); return true;
        case 6: runExer06(); return true;
        default: return false;
    }
}

}

int main(int argc, char* argv[]) {
    int choice = 0;

    if (argc >= 2) {
        try {
            choice = std::stoi(argv[1]);
        } catch (...) {
            choice = 0;
        }
    } else {
        printMenu();
        if (!(std::cin >> choice)) {
            return 1;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (!runExercise(choice)) {
        std::cerr << "Questao invalida. Use um numero de 1 a 6.\n";
        return 1;
    }
    return 0;
}
