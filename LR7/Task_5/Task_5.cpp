#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <unordered_set>
#include <algorithm>
struct Slave {
    bool alive;
    int id;
    std::string name;
    std::vector<int> barrels;
};


int main() {

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
        return -1;
    }   else {
        std::cout << "с наступающим Новым годом!\n";
    }
    std::sort(deadOnlyBarrels.begin(), deadOnlyBarrels.end());
    std::cout << "бочки, из которых пили только мертвые рабы: ";
    for (const auto& barrel : deadOnlyBarrels) {
        std::cout << barrel << " ";
    }

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
            if (barrel == poisonedBarrel) {
                slave.alive = false; // Раб выпил из отравленной бочки
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
        return -1;
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
            if (barrel == poisonedBarrel) {
                slave.alive = false; // Раб выпил из отравленной бочки
                std::cout << "Press F " << slave.name << std::endl;
                break;
            }
        }
    }
        std::cout << "oпределенная отравленная бочка: " << foundBarrel << std::endl;

    return 0;
}




}
