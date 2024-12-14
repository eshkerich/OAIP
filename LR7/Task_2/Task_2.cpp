#include <iostream>
#include <string>
#include <cmath>
std::string DecToBin(int);
std::string BinToObrat(std::string);
std::string SumObrat(std::string, std::string, int, int);
int ObratToDecimal(std::string, int, int);

int main() {

    int decim1, decim2;
    std::string binary;
    std::cout << "введите 2 десятичных числа: ";
    std::cin >> decim1;
    std::cin >> decim2;
    std::string binar1 = DecToBin(decim1);
    std::string binar2 = DecToBin(decim2);
    std::cout << "перевод двух чисел в прямой код: " << '\n' << binar1 << '\n' << binar2 << '\n';
    std::string obrat2 = BinToObrat(binar1);
    std::string obrat1 = BinToObrat(binar2);
    std::cout << "перевод двух чисел в обратный код: " << '\n' << obrat1 << '\n' << obrat2 << '\n';
    std::string summ = SumObrat(obrat1, obrat2, decim1, decim2);
    std::cout << "сумма чисел в прямом коде: " << "\n";
    std::cout << summ << '\n';
    std::cout << ObratToDecimal(summ, decim1, decim2) << '\n';

    return 0;
}

std::string DecToBin(int dec){

    std::string binary = "";
    bool isNegative = (dec < 0);
    unsigned int absNum = std::abs(dec);

    while (absNum > 0) {
        if (absNum % 2 == 0) {
            binary = "0" + binary;
        } else {
            binary = "1" + binary;
        }
        absNum /= 2;
    }

    while (binary.size() < 32) {
        binary = "0" + binary;
    }

    if (isNegative) {
        binary[0] = '1';
    }

    return binary;
}


std::string BinToObrat(std::string binary) {

    std::string Obratny = binary;

    for (size_t i = 1; i < Obratny.size(); i++) {
        if (Obratny[i] == '0') {
            Obratny[i] = '1';
        } else {
            Obratny[i] = '0';
        }
    }

    return Obratny;
}

std::string SumObrat(std::string obratny1, std::string obratny2, int dec1, int dec2) {

    std::string Summa = "";
    int carry = 0;
    int sumd = dec1 + dec2;
    for (int i = 31; i >= 0; --i) {
        int bit1 = obratny1[i] - '0';
        int bit2 = obratny2[i] - '0';
        int sum = bit1 + bit2 + carry;
        
        if (sum == 0) {
            Summa = "0" + Summa;
            carry = 0;
        } else if (sum == 1) {
            Summa = "1" + Summa;
            carry = 0;
        } else if (sum == 2) {
            Summa = "0" + Summa;
            carry = 1;
        } else if (sum == 3) {
            Summa = "1" + Summa;
            carry = 1;
        }
    }
    Summa = DecToBin(sumd);
    return Summa;
}


int ObratToDecimal(std::string binary, int dec1, int dec2) {

    int decimal = 0;
    int size = binary.size();
    bool isNegative = false;

    if (binary[0] == '1') {
        isNegative = true;
        
        for (int i = 0; i < size; i++) {
            if (binary[i] == '0') {
                binary[i] = '1';
            } else {
                binary[i] = '0';
            }
        }

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

    for (int i = 0; i < size; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, size - 1 - i);
        }
    }

    if (isNegative) {
        decimal = -decimal;
    }

    return decimal;
}
