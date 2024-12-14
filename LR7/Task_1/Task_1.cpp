#include <iostream>
#include <string>
#include <cmath>

int binaryToDecimal(std::string binary) {
    int decimal = 0;
    int size = binary.size();
    bool isNegative = false;

    // проверяем, является ли число отрицательным
    if (binary[0] == '1') {
        isNegative = true;
        
        // инвертируем все биты
        for (int i = 0; i < size; i++) {
            if (binary[i] == '0') {
                binary[i] = '1';
            } else {
                binary[i] = '0';
            }
        }

        // добавляем 1
        int carry = 1;
        for (int i = size - 1; i >= 0; i--) {
            if (binary[i] == '1' && carry == 1) {
                binary[i] = '0';
            } else if (binary[i] == '0' && carry == 1) {
                binary[i] = '1';
                carry = 0;
            }
        }
    }

    // преобразуем двоичное число в десятичное
    for (int i = 0; i < size; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, size - 1 - i);
        }
    }

    // если число отрицательное, добавляем знак минус
    if (isNegative) {
        decimal = -decimal;
    }

    return decimal;
}

int main() {
    std::string binary;
    std::cout << "введите двоичное число: ";
    std::cin >> binary;

    int decimal = binaryToDecimal(binary);
    std::cout << "десятичное число: " << decimal << std::endl;

    return 0;
}
