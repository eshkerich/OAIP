#include <iostream>
#include <cstring> 

int main() {

    const int MAX_LENGTH = 80;
    char input[MAX_LENGTH + 1];

    int index = 0;
    int round = 0; // ()
    int square = 0; // []
    int curly = 0; // {}


     std::cout << "введите текст: ";

    while (true) {
        char ch = getchar();
        if (ch == '\n') {
            input[index] = '\0';
            if (index == 0 || ch == '\n') {
                break;
            }
        } else {
            if (index < MAX_LENGTH) {
                input[index++] = ch;
                switch (ch) {
                    case '(': round++; break;
                    case ')': round++; break;
                    case '[': square++; break;
                    case ']': square++; break;
                    case '{': curly++; break;
                    case '}': curly++; break;
                    default: break;
                }
            } else {
                std::cerr << "ошибка: строка превышает 80 символов." << std::endl;
                while ((ch = getchar()) != '\n');
            }
        }
    }

    std::cout << "исходный текст: ";
    for (int i = 0; i < index; i++) {
        std::cout << input[i] ;
    }
    std::cout << std::endl;
    std::cout << "количество круглых скобок: " << round << std::endl;
    std::cout << "количество квадратных скобок: " << square << std::endl;
    std::cout << "количество фигурных скобок: " << curly << std::endl;
    getchar();
    return 0;
}

  