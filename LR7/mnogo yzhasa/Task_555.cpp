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


    int poisonedBarrel, bespolezniInt;
    std::cout << "введите номер отравленной бочки: ";
    std::cin >> poisonedBarrel;
    std::cout << "отправляйтесь пожалуйста в ад)\n";
    std::cout << "1. спасибо\n"     ;
    std::cout << "2. хорошо\n"      ;
    std::cout << "3. замечательно\n";
    std::cout << "Choice: "         ;
    std::cin >> bespolezniInt;

    // Откидываем 30 бочек
    int totalBarrels = 240;
    int discardedBarrels = 30;
    int remainingBarrels = 210;

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
        std::cout << std::endl;
    } else {
        std::cout << "Повезло, можешь ещё день побегать\n";
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

    std::cout << "бочки, из которых пили только мертвые рабы: ";
    for (const auto& barrel : deadOnlyBarrels) {
        std::cout << barrel << " ";
    }
    std::cout << std::endl;


    for (int i = 0; i < 5; ++i) {
            slaves[i].barrels = {};
    }


    // Вывод состояния рабов и номеров бочек
    for (const auto& slave : slaves) {
        std::cout << "Раб " << slave.name << " (ID: " << slave.id << ") ";
        if (slave.alive) {
            std::cout << "жив и будет пить из бочек: ";
            for (const auto& b : slave.barrels) {
                std::cout << b << " ";
            }
        } else {
            std::cout << "мертв";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;





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



    // Распределение оставшихся бочек между живыми рабами
    for (const auto& barrel : deadOnlyBarrels) {
        std::bitset<5> bits(barrel);
        for (int i = 0; i < 5; ++i) {
            if (bits[i] && slaves[i].alive) {
                slaves[i].barrels.push_back(barrel);
            }
        }
    }


    // Проверка состояния рабов через 48 часов
    for (auto& slave : slaves) {
        for (const auto& barrel : slave.barrels) {
            if (barrel == poisonedBarrel) {
                slave.alive = false; // Раб выпил из отравленной бочки
                break;
            }
        }
    }

    // Запись номеров бочек, из которых пили только мертвые рабы после 48 часов
    std::unordered_map<int, int> barrelCount;
    for (const auto& slave : slaves) {
        if (!slave.alive) {
            for (const auto& barrel : slave.barrels) {
                barrelCount[barrel]++;
            }
        }
    }

    // Поиск бочки, из которой пили больше всего мертвых рабов
    int mostCommonBarrel = -1;
    int maxCount = 0;
    for (const auto& pair : barrelCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostCommonBarrel = pair.first;
        }
    }

    std::cout << "Номер отравленной бочки: " << mostCommonBarrel << std::endl;



    /* Запись номеров бочек, из которых пили только мертвые рабы после 48 часов
    std::vector<int> deadOnlyBarrels48;
    std::unordered_set<int> deadBarrels2;
    std::unordered_set<int> allBarrels2;
    for (const auto& slave : slaves) {
        if (!slave.alive) {
            for (const auto& barrel : slave.barrels) {
                deadBarrels2.insert(barrel);
            }
        }
        for (const auto& barrel : slave.barrels) {
            allBarrels2.insert(barrel);
        }
    }

    for (const auto& barrel : deadBarrels2) {
        bool onlyDead = true;
        for (const auto& slave : slaves) {
            if (slave.alive && std::find(slave.barrels.begin(), slave.barrels.end(), barrel) != slave.barrels.end()) {
                onlyDead = false;
                break;
            }
        }
        if (onlyDead) {
            deadOnlyBarrels48.push_back(barrel);
        }
    }

    // Вывод номеров бочек, из которых пили только мертвые рабы после 48 часов
    std::cout << "Бочки, из которых пили только мертвые рабы после 48 часов: ";
    for (const auto& barrel : deadOnlyBarrels48) {
        std::cout << barrel << " ";
    }
    std::cout << std::endl; */
    













    } else {





    }


    return 0;
}

