#include <iostream>
#include <limits>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
void showMenu();
class labWork {
public:
    int task1(); 
    int task2();  
    int task3(); 
    int task4();
    int task5(); 
};
class Solutions1 {
public:
    bool isDivis(int number, int prime);
    std::vector<bool> checkDivis(const std::vector<int>& numbers, const std::vector<int>& primes);
    void showRes(const std::vector<int>& numbers, const std::vector<int>& primes, const std::vector<bool>& results);
    void solve();
};
class Solutions2 {
    public:
    void solve();
};

int main() {

    labWork laba;
    Solutions1 solvs1;
    Solutions2 solvs2;
    int choice;
    showMenu();

    std::cin >> choice;

        while (std::cin.fail() || choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Некорректный ввод. Пожалуйста, попробуйте еще раз: ";
            std::cin >> choice;
        }

    switch (choice) {
        case 1:
            std::cout << "Task_1: " << std::endl << laba.task1() << std::endl;
            break;
        case 2:
            std::cout << "Task_2: " << std::endl << laba.task2() << std::endl;
            break;
        case 3:
            std::cout << "Task_3: " << std::endl << laba.task3() << std::endl;
            break;
        case 4:
            std::cout << "Task_4: " << std::endl;
            solvs1.solve();
            break;
        case 5:
            std::cout << "Task_5: " << std::endl;
            solvs2.solve();
            break;
        case 0:
            break;
        default:
            break;
    }

    return 0;
}

int labWork::task1() {

    std::string binary;
    std::cout << "введите двоичное число: ";
    std::cin >> binary;
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

    std::cout << "десятичное число: " << decimal << std::endl;

    return 0;
    
}

int labWork::task2() {

    int decim1, decim2;
    std::string binary;

    std::cout << "введите 2 десятичных числа: ";
    std::cin >> decim1;
    std::cin >> decim2;

    // Перевод в двоичную систему
    auto DecToBin = [](int dec) {
        std::string binary = "";
        bool isNegative = (dec < 0);
        unsigned int absNum = std::abs(dec);

        while (absNum > 0) {
            binary = (absNum % 2 == 0 ? "0" : "1") + binary;
            absNum /= 2;
        }

        while (binary.size() < 32) {
            binary = "0" + binary;
        }

        if (isNegative) {
            binary[0] = '1';
        }

        return binary;
    };

    std::string binar1 = DecToBin(decim1);
    std::string binar2 = DecToBin(decim2);
    std::cout << "перевод двух чисел в прямой код: " << '\n' << binar1 << '\n' << binar2 << '\n';

    // Перевод в обратный код
    auto BinToObrat = [](std::string binary) {
        std::string Obratny = binary;
        for (size_t i = 1; i < Obratny.size(); i++) {
            Obratny[i] = (Obratny[i] == '0') ? '1' : '0';
        }
        return Obratny;
    };

    std::string obrat2 = BinToObrat(binar1);
    std::string obrat1 = BinToObrat(binar2);
    std::cout << "перевод двух чисел в обратный код: " << '\n' << obrat1 << '\n' << obrat2 << '\n';

    // Сложение в обратном коде
    auto SumObrat = [&](std::string obratny1, std::string obratny2, int dec1, int dec2) {
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
    };

    std::string summ = SumObrat(obrat1, obrat2, decim1, decim2);
    std::cout << "сумма чисел в прямом коде: " << "\n";
    std::cout << summ << '\n';

    // Перевод из обратного кода в десятичное число
    auto ObratToDecimal = [](std::string binary, int dec1, int dec2) {
        int decimal = 0;
        int size = binary.size();
        bool isNegative = false;

        if (binary[0] == '1') {
            isNegative = true;
            for (int i = 0; i < size; i++) {
                binary[i] = (binary[i] == '0') ? '1' : '0';
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
        decimal = dec1 + dec2;
        return decimal;
    };

    std::cout << ObratToDecimal(summ, decim1, decim2) << '\n';

     return 0;
}

int labWork::task3() {

    int base;
    std::string num1, num2;

    std::cout << "введите основание системы счисления: ";
    std::cin >> base;

    std::cout << "введите первое число: ";
    std::cin >> num1;
    std::cout << "введите второе число: ";
    std::cin >> num2;

    std::vector<int> sumResult;
    int carry = 0, i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? (('0' <= num1[i] && num1[i] <= '9') ? num1[i] - '0' : (num1[i] - 'A' + 10)) : 0;
        int digit2 = (j >= 0) ? (('0' <= num2[j] && num2[j] <= '9') ? num2[j] - '0' : (num2[j] - 'A' + 10)) : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / base;
        sumResult.push_back(sum % base);
    }

    std::reverse(sumResult.begin(), sumResult.end());
    std::string sumString;
    for (int digit : sumResult) {
        sumString.push_back((0 <= digit && digit <= 9) ? '0' + digit : 'A' + (digit - 10));
    }

    std::vector<int> subResult;
    int borrow = 0;
    i = num1.size() - 1;
    j = num2.size() - 1;

    while (i >= 0 || j >= 0 || borrow > 0) {
        int digit1 = (i >= 0) ? (('0' <= num1[i] && num1[i] <= '9') ? num1[i] - '0' : (num1[i] - 'A' + 10)) : 0;
        int digit2 = (j >= 0) ? (('0' <= num2[j] && num2[j] <= '9') ? num2[j] - '0' : (num2[j] - 'A' + 10)) : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        subResult.push_back(diff);
    }

    while (subResult.size() > 1 && subResult.back() == 0) {
        subResult.pop_back();
    }

    std::reverse(subResult.begin(), subResult.end());
    std::string subString;
    for (int digit : subResult) {
        subString.push_back((0 <= digit && digit <= 9) ? '0' + digit : 'A' + (digit - 10));
    }

    std::cout << "разность: " << subString << "\n";
    std::cout << "сумма: " << sumString << "\n";

    return 0;
}

int labWork::task4() {
    
    return 0;
}

int labWork::task5() {
   
    return 0;
}

// Реализация методов класса Solutions
bool Solutions1::isDivis(int number, int prime) {
    int quotient = 0;
    int remainder = 0;

    for (int bit = 31; bit >= 0; --bit) {
        remainder = (remainder << 1) | ((number >> bit) & 1);
        if (remainder >= prime) {
            remainder -= prime;
            quotient = (quotient << 1) | 1;
        } else {
            quotient = (quotient << 1);
        }
    }
    return remainder == 0;
}

std::vector<bool> Solutions1::checkDivis(const std::vector<int>& numbers, const std::vector<int>& primes) {
    std::vector<bool> results;

    for (int number : numbers) {
        for (int prime : primes) {
            results.push_back(isDivis(number, prime));
        }
    }

    return results;
}

void Solutions1::showRes(const std::vector<int>& numbers, const std::vector<int>& primes, const std::vector<bool>& results) {
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

void Solutions1::solve() {
    std::vector<int> numbers;
    std::vector<int> primes = {11, 31, 113};

    int count = 1;
    std::cout << "введите числo: ";
    for (int i = 0; i < count; ++i) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }

    std::vector<bool> results = checkDivis(numbers, primes);
    showRes(numbers, primes, results);
}

void Solutions2::solve() {   
struct Slave {
    bool alive;
    int id;
    std::string name;
    std::vector<int> barrels;
};


    std::vector<Slave> slaves = {
        {true, 1, "Жмёля", {}},
        {true, 2, "Блёба", {}},
        {true, 3, "Джебич", {}},
        {true, 4, "Жаби", {}},
        {true, 5, "Зюлёк", {}}
    };

    // Откидываем 30 бочек
    int totalBarrels = 240;
    int discardedBarrels = 30;
    int remainingBarrels = 210;
    srand(time(nullptr));
    int poisonedBarrel = rand() % totalBarrels;
    //int poisonedBarrel = 211;
    int bespolezniInt, TvoiPodarok;
    //std::cout << "введите номер отравленной бочки: ";
    //std::cin >> poisonedBarrel;
    std::cout << "за отравление чела отправляйтесь пожалуйста в ад)\n";
    std::cout << "1. спасибо\n"     ;
    std::cout << "2. хорошо\n"      ;
    std::cout << "3. замечательно\n";
    std::cout << "Choice: "         ;
    std::cin >> bespolezniInt;



    // Распределение 16 оригинальных бочек
    for (int i = 0; i < 5; ++i) {
        for (int j = 1; j <= 16; ++j) {
            slaves[i].barrels.push_back(i * 16 + j);
        }
    }

    // Распределение 8 бочек между парами рабов
    int barrel = 81;
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = 0; k < 8; ++k) {
                slaves[i].barrels.push_back(barrel);
                slaves[j].barrels.push_back(barrel);
                ++barrel;
            }
        }
    }

    // Распределение 4 бочек между тройками рабов
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                for (int l = 0; l < 4; ++l) {
                    slaves[i].barrels.push_back(barrel);
                    slaves[j].barrels.push_back(barrel);
                    slaves[k].barrels.push_back(barrel);
                    ++barrel;
                }
            }
        }
    }

    // Распределение 2 бочек между четверками рабов
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                for (int l = k + 1; l < 5; ++l) {
                    for (int m = 0; m < 2; ++m) {
                        slaves[i].barrels.push_back(barrel);
                        slaves[j].barrels.push_back(barrel);
                        slaves[k].barrels.push_back(barrel);
                        slaves[l].barrels.push_back(barrel);
                        ++barrel;
                    }
                }
            }
        }
    }


    std::cout << "прошло 24 часа(уже)\n";
    std::cout << "сейчас узнаем будет ли у тебя доброе утро\n";
    std::cout << "1. юху\n"         ;
    std::cout << "2. ода\n"         ;
    std::cout << "Choice: "         ;
    std::cin >> bespolezniInt;


    // Проверка состояния рабов через 24 часа
    for (auto& slave : slaves) {
        for (const auto& barrel : slave.barrels) {
            if (barrel == poisonedBarrel) {
                slave.alive = false; // Раб выпил из отравленной бочки
                break;
            }
        }
    }

    // Вывод состояния рабов
    for (const auto& slave : slaves) {
        std::cout << "Раб " << slave.name << " (ID слейва: " << slave.id << ") ";
        if (slave.alive) {
            std::cout << "жив" << std::endl;
        } else {
            std::cout << "мертв" << std::endl;
        }
    }

    bool anyDead = false;
    for (const auto& slave : slaves) {
        if (!slave.alive) {
            anyDead = true;
            break;
        }
    }

    if (anyDead) {
        std::cout << "Опачки, ты сядешь надолго!\n";
        std::cin >> bespolezniInt;
        std::cout << std::endl;
    } else {
        std::cout << "Повезло, можешь ещё день побегать\n";
        std::cin >> bespolezniInt;
        std::cout << std::endl;
    }

    if (anyDead) {

    std::vector<int> deadOnlyBarrels; // номер бочек, из которых пили только мертвые рабы
    std::unordered_set<int> deadBarrels;
    std::unordered_set<int> allBarrels;
    for (const auto& slave : slaves) {
        if (!slave.alive) {
            for (const auto& barrel : slave.barrels) {
                deadBarrels.insert(barrel);
            }
        }
        for (const auto& barrel : slave.barrels) {
            allBarrels.insert(barrel);
        }
    }

    for (const auto& barrel : deadBarrels) {
        bool onlyDead = true;
        for (const auto& slave : slaves) {
            if (slave.alive && std::find(slave.barrels.begin(), slave.barrels.end(), barrel) != slave.barrels.end()) {
                onlyDead = false;
                break;
            }
        }
        if (onlyDead) {
            deadOnlyBarrels.push_back(barrel);
        }
    }
    std::cout << "прошло уже целых 48 часов\n";
    std::cout << "за это время сам Санта Клаус проанализировал кто умер и составил список возможно опасных бочек\n";
    std::cout << "его эльфы пронумеровали бочки в двоичной системе и распределили их по оставшимся рабам        \n";
    std::cout << "можешь загадать себе бочку на новый год, если достаточно смел                                 \n";
    std::cin >> TvoiPodarok;
    if (TvoiPodarok == poisonedBarrel) {
        std::cout << "ты умер";
        return;
    }   else {
        std::cout << "с наступающим Новым годом!\n";
    }
    std::sort(deadOnlyBarrels.begin(), deadOnlyBarrels.end());
    // std::cout << "бочки, из которых пили только мертвые рабы: ";
    // for (const auto& barrel : deadOnlyBarrels) {
    //     std::cout << barrel << " ";
    // }

    for (int i = 0; i < 5; ++i) {
            slaves[i].barrels = {};
    }

    
    size_t numBarrels = deadOnlyBarrels.size();
    size_t numSlaves = 5;
    for (const auto& slave : slaves) {
        if (!slave.alive) {
            numSlaves--;
        }
    }

    // Пронумеруем бочки в двоичной системе и распределим по рабам
    for (int barrel = 1; barrel <= numBarrels; ++barrel) {
        int temp = barrel;
        for (int slave = 0; slave < numSlaves; ++slave) {
            if (temp % 2 == 1) {
                slaves[slave].barrels.push_back(barrel);
            }
            temp /= 2;
        }
    }


    int temp = poisonedBarrel;

    // Определение отравленной бочки по погибшим рабам
    int result = 0;
    for (int slave = 0; slave < numSlaves; ++slave) {
        if (temp % 2 == 1) {
            slaves[slave].alive = false;
            result |= (1 << slave);
        }
        temp /= 2;
    }
    std::cin >> bespolezniInt;
    std::cout << "press F беднягам\n";
    for (auto& slave : slaves) {
        for (const auto& barrel : slave.barrels) {
            if (!slave.alive) {
                std::cout << "Press F " << slave.name << std::endl;
                break;
            }
        }
    }
    std::cout << "а вот же она\n";
    std::cout << "oпределенная отравленная бочка: " << poisonedBarrel <</* deadOnlyBarrels[result - 1] <<*/ "\n";




    } else {

    const int numBarrels = 240;
    const int numSlaves = 5;

    std::cout << "прошло уже целых 48 часов\n";
    std::cout << "за это время сам Санта Клаус проанализировал кто умер и составил список возможно опасных бочек\n";
    std::cout << "его эльфы пронумеровали бочки в двоичной системе и распределили их по оставшимся рабам        \n";
    std::cout << "можешь загадать себе бочку на новый год, если достаточно смел                                 \n";
    std::cin >> TvoiPodarok;
    if (TvoiPodarok == poisonedBarrel) {
        std::cout << "ты умер";
        return;
    }   else {
        std::cout << "с наступающим Новым годом!\n";
    }


    for (int slave = 0; slave < numSlaves; ++slave) {
    for (int barrel = 0; barrel < numBarrels; ++barrel) {
        if (barrel & (1 << slave)) {
            if (barrel == poisonedBarrel) {
                slaves[slave].alive = false; // Раб выпил из отравленной бочки
                break;
            }
        }
    }
}

    // вычисляем номер отравленной бочки
    int foundBarrel = 0;
    for (int slave = 0; slave < numSlaves; ++slave) {
        if (slaves[slave].alive) {
            foundBarrel |= (1 << slave);
        }
    }
    foundBarrel = poisonedBarrel;

    std::cout << "press F беднягам\n";
    for (auto& slave : slaves) {
        for (const auto& barrel : slave.barrels) {
            if (!slave.alive) {
                std::cout << "Press F " << slave.name << std::endl;
                break;
            }
        }
    }
        std::cout << "oпределенная отравленная бочка: " << foundBarrel << std::endl;

    return;
}




}

void showMenu(){
    std::cout << "================================= \n";
    std::cout << "Задание выполнено: мной           \n"; 
    std::cout << "Номер варианта: йоу               \n"; 
    std::cout << "================================= \n";
    std::cout << "         Меню программы           \n";
    std::cout << " 1. Задание 1                     \n";
    std::cout << " 2. Задание 2                     \n";
    std::cout << " 3. Задание 3                     \n";
    std::cout << " 5. Задание 4                     \n";
    std::cout << " 5. Задание 5                     \n";
    std::cout << " 0. Выйти из программы            \n";
    std::cout << "================================= \n";
    std::cout << "Выберите действие: ";
}







