#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для проверки состояния рабов через 24 часа
int checkSlaves(vector<int>& slaves) {
    int result = 0;
    for (int i = 0; i < slaves.size(); ++i) {
        if (slaves[i] == 1) {
            result += pow(2, i);
        }
    }
    return result;
}

int main() {
    int numBarrels = 240;
    int numSlaves = 5;
    vector<int> slaves(numSlaves, 0);
    vector<int> barrels(numBarrels, 0);

    // Заполняем бочки номерами
    for (int i = 0; i < numBarrels; ++i) {
        barrels[i] = i + 1;
    }

    // Распределяем бочки между рабами
    for (int i = 0; i < numBarrels; ++i) {
        for (int j = 0; j < numSlaves; ++j) {
            if (i & (1 << j)) {
                cout << "Раб " << j + 1 << " пьет из бочки " << barrels[i] << endl;
            }
        }
    }

    // Симулируем проверку состояния рабов через 24 часа
    cout << "Введите состояние рабов через 24 часа (0 - жив, 1 - умер):" << endl;
    for (int i = 0; i < numSlaves; ++i) {
        cin >> slaves[i];
    }

    // Определяем номер отравленной бочки
    int poisonedBarrel = checkSlaves(slaves);
    cout << "Отравленная бочка: " << poisonedBarrel << endl;

    return 0;
}
