#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int chrToVal(char c);
char valToChr(int value);
std::string sumNums(const std::string& num1, const std::string& num2, int base);
std::string subNums(const std::string& num1, const std::string& num2, int base);

int main() {
    int base;
    std::string num1, num2, operation;

    std::cout << "введите основание системы счисления: ";
    std::cin >> base;
    // while(base < 2 || base > 36){
    //     std::cout << "wrong input \n enter the right number: ";
    //     std::cin >> base;
    // }
    std::cout << "введите первое число: ";
    std::cin >> num1;
    std::cout << "введите второе число: ";
    std::cin >> num2;
    std::cout << "разность: " << subNums(num1, num2, base) << "\n";
    std::cout << "сумма: "    << sumNums(num1, num2, base) << "\n";

    // std::cout << "1. Сумма" << '\n';
    // std::cout << "2. Разность" << '\n';
    // std::cout << "Choice: ";
    // int i = 0;
    // std::cin >> i;
    // if (i == 1) {
    // std::cout << "сумма: " << sumNums(num1, num2, base) << "\n";
    // } else if (i == 2){
    // std::cout << "разность: " << subNums(num1, num2, base) << "\n";
    // } else {return -1;}

    return 0;
}

int chrToVal(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'Z') return c - 'A' + 10;
    if ('a' <= c && c <= 'z') return c - 'a' + 10;
    return -1;
}

char valToChr(int value) {
    if (0 <= value && value <= 9) return '0' + value;
    if (10 <= value && value <= 35) return 'A' + (value - 10);
    return '?';
}

std::string sumNums(const std::string& num1, const std::string& num2, int base) {

    std::vector<int> result;
    int carry = 0, i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? chrToVal(num1[i--]) : 0;
        int digit2 = (j >= 0) ? chrToVal(num2[j--]) : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / base;
        result.push_back(sum % base);
    }

    std::reverse(result.begin(), result.end()); // O(n)
    std::string resString;
    for (int digit : result) {
        resString.push_back(valToChr(digit));
    }

    return resString;
}

std::string subNums(const std::string& num1, const std::string& num2, int base) {
    std::vector<int> result;
    int borrow = 0, i = num1.size() - 1, j = num2.size() - 1;
    while (i >= 0 || j >= 0 || borrow > 0) {
        int digit1 = (i >= 0) ? chrToVal(num1[i--]) : 0;
        int digit2 = (j >= 0) ? chrToVal(num2[j--]) : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff);
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back(); //O(n)
    }

    std::reverse(result.begin(), result.end()); // O(n)
    std::string resString;
    for (int digit : result) {
        resString.push_back(valToChr(digit));
    }

    return resString;
}
