#include <iostream>
#include <vector>
#include <bitset>
#include <string>

struct Slave {
    bool alive;
    int id;
    std::string name;
    std::vector<int> barrels;
};

int main() {
    const int numBarrels = 240;
    const int numSlaves = 5;
    std::vector<Slave> slaves = {
        {true, 1, "Жмёля", {}},
        {true, 2, "Блёба", {}},
        {true, 3, "Джебич", {}},
        {true, 4, "Жаби", {}},
        {true, 5, "Зюлёк", {}}
    };

    // Первый шаг: разделим бочки на 2 группы
    std::vector<int> group1, group2;
    for (int barrel = 1; barrel <= numBarrels; ++barrel) {
        if (barrel <= 120) {
            group1.push_back(barrel);
        } else {
            group2.push_back(barrel);
        }
    }

    // Симуляция: предположим, что отравлена бочка №130
    int poisonedBarrel = 137;
    bool firstGroup = poisonedBarrel <= 120;

    // Определение группы с отравленной бочкой
    if (firstGroup) {
        std::cout << "Отравленная бочка находится в первой группе.\n";
    } else {
        std::cout << "Отравленная бочка находится во второй группе.\n";
        group1 = group2;
    }

    // Второй шаг: пронумеруем бочки в двоичной системе и распределим по рабам
    for (int barrel : group1) {
        std::bitset<numSlaves> binaryBarrel(barrel);
        for (int slave = 0; slave < numSlaves; ++slave) {
            if (binaryBarrel[slave]) {
                slaves[slave].barrels.push_back(barrel);
            }
        }
    }

    // Определение отравленной бочки по погибшим рабам
    std::bitset<numSlaves> poisonedBinary(poisonedBarrel);
    int result = 0;
    for (int slave = 0; slave < numSlaves; ++slave) {
        if (poisonedBinary[slave]) {
            slaves[slave].alive = false;
            result |= (1 << slave);
        }
    }

    std::cout << "Определенная отравленная бочка: №" << result + 1 << "\n";
    return 0;
}
