#include <iostream>
#include <vector>

// прототипы функций
bool isDivisible(int number, int prime);
std::vector<bool> checkDivisibility(const std::vector<int>& numbers, const std::vector<int>& primes);
void printResults(const std::vector<int>& numbers, const std::vector<int>& primes, const std::vector<bool>& results);

int main() {
    std::vector<int> numbers;
    std::vector<int> primes = {11, 31, 113};

    int count;
    std::cout << "введите количество чисел для проверки: ";
    std::cin >> count;

    std::cout << "введите числа:\n";
    for (int i = 0; i < count; ++i) { // O(n)
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }
    std::vector<bool> results = checkDivisibility(numbers, primes);
    printResults(numbers, primes, results);

    return 0;
}

// реализация функций
bool isDivisible(int number, int prime) {
    int quotient = 0;
    int remainder = 0;

    // деления через побитовые операции
    // O(log(n))
    for (int bit = 31; bit >= 0; --bit) {
        remainder = (remainder << 1) | ((number >> bit) & 1); // добавляем бит к остатку (<< O(1), | O(1))
        if (remainder >= prime) { // если остаток больше делителя
            remainder -= prime; // вычитаем делитель (через побитовые операции)
            quotient = (quotient << 1) | 1;
        } else {
            quotient = (quotient << 1);
        }
    }
    return remainder == 0;
}

std::vector<bool> checkDivisibility(const std::vector<int>& numbers, const std::vector<int>& primes) {
    std::vector<bool> results;

    // O(m * n * log(max_number))
    for (int number : numbers) {// O(n)
        for (int prime : primes) {// O(m)
            results.push_back(isDivisible(number, prime)); //проверка делимости O(log(max_number))
        }
    }

    return results;
}

void printResults(const std::vector<int>& numbers, const std::vector<int>& primes, const std::vector<bool>& results) {
    size_t idx = 0;

    for (int number : numbers) {
        for (int prime : primes) {
            std::cout << "число " << number;
            if (results[idx++]) {
                std::cout << " делится ";
            } else {
                std::cout << " не делится ";
            }
            std::cout << "на " << prime << ".\n";
        }
    }
}
