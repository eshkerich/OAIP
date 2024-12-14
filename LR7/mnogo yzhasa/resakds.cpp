#include <iostream>
#include <vector>
#include <string>

struct Slave {
    bool alive;
    int id;
    std::string name;
    std::vector<int> barrels;
};

int main() {
    const int numBarrels = 16;
    const int numSlaves = 4;
    std::vector<Slave> slaves = {
        {true, 1, "Жмёля", {}},
        {true, 2, "Блёба", {}},
        {true, 3, "Джебич", {}},
        {true, 4, "Жаби", {}}
    };

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

    // Вывод информации о состоянии рабов и номерах бочек
    for (const auto& slave : slaves) {
        std::cout << "Раб " << slave.name << " (ID слейва: " << slave.id << ") ";
        if (slave.alive) {
            std::cout << "жив";
        } else {
            std::cout << "мертв";
        }
        std::cout << ", бочки, которые будет пить: ";
        for (const auto& barrel : slave.barrels) {
            std::cout << barrel << " ";
        }
        std::cout << "\n";
    }

    // Симуляция: предположим, что отравлена бочка №10
    int poisonedBarrel = 10;
    int temp = poisonedBarrel;
    std::cout << "Отравлена бочка №" << poisonedBarrel << "\n";

    // Определение отравленной бочки по погибшим рабам
    int result = 0;
    for (int slave = 0; slave < numSlaves; ++slave) {
        if (temp % 2 == 1) {
            slaves[slave].alive = false;
            result |= (1 << slave);
        }
        temp /= 2;
    }

    // Вывод информации о состоянии рабов после симуляции
    for (const auto& slave : slaves) {
        std::cout << "Раб " << slave.name << " (ID слейва: " << slave.id << ") ";
        if (slave.alive) {
            std::cout << "жив";
        } else {
            std::cout << "мертв";
        }
        std::cout << "\n";
    }

    std::cout << "Определенная отравленная бочка: №" << result << "\n";
    return 0;
}
