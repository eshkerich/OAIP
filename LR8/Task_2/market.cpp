#include <iostream>
#include <fstream>
#include <cstring>
#include "market.h"

// Функция создания массива записей
Market* createArray(int& size, int choice) {
    Market* array = nullptr;
    size = 0;

    if (choice == 1) {
        int n;
        std::cout << "Введите количество записей для ввода: ";
        std::cin >> n;
        std::cin.ignore();
        array = new Market[n];
        for (int i = 0; i < n; i++) {
            std::cout << "Введите данные для записи " << i + 1 << ":\n";
            array[i].id = i + 1;
            std::cout << "Ф.И.О.: ";
            std::cin.getline(array[i].fullName, NAME_LENGTH);
            std::cout << "Улица: ";
            std::cin.getline(array[i].street, STREET_LENGTH);
            std::cout << "Номер дома: ";
            std::cin >> array[i].houseNumber;
            std::cin.ignore();
            std::cout << "Дата постановки на учет: ";
            std::cin.getline(array[i].registrationDate, DATE_LENGTH);
        }
        size = n;
    } else if (choice == 2) {
        int n = 0;
        array = new Market[1];
        while (true) {
            std::cout << "Введите данные для записи " << n + 1 << ":\n";
            array[n].id = n + 1;
            std::cout << "Ф.И.О.: ";
            std::cin.getline(array[n].fullName, NAME_LENGTH);
            std::cout << "Улица: ";
            std::cin.getline(array[n].street, STREET_LENGTH);
            std::cout << "Номер дома: ";
            std::cin >> array[n].houseNumber;
            std::cin.ignore();
            if (array[n].houseNumber > 50) {
                std::cout << "Номер дома больше 50\n";
                break;
            }
            std::cout << "Дата постановки на учет: ";
            std::cin.getline(array[n].registrationDate, DATE_LENGTH);
            n++;
            array = (Market*)realloc(array, (n + 1) * sizeof(Market));
        }
        size = n;
    } else if (choice == 3) {
        int n = 0;
        array = new Market[1];
        while (true) {
            std::cout << "Введите данные для записи " << n + 1 << ":\n";
            array[n].id = n + 1;
            std::cout << "Ф.И.О.: ";
            std::cin.getline(array[n].fullName, NAME_LENGTH);
            std::cout << "Улица: ";
            std::cin.getline(array[n].street, STREET_LENGTH);
            std::cout << "Номер дома: ";
            std::cin >> array[n].houseNumber;
            std::cin.ignore();
            std::cout << "Дата постановки на учет: ";
            std::cin.getline(array[n].registrationDate, DATE_LENGTH);
            n++;
            array = (Market*)realloc(array, (n + 1) * sizeof(Market));
            char continueInput;
            std::cout << "Продолжить ввод? (y/n): ";
            std::cin >> continueInput;
            std::cin.ignore();
            if (continueInput == 'n') {
                break;
            }
        }
        size = n;
    }

    return array;
}

// Функция отображения массива записей
void displayArray(Market* array, int size) {
    std::cout << "\nСписок записей:\n";
    std::cout << "------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Запись " << array[i].id << ":\n";
        std::cout << "Ф.И.О.: " << array[i].fullName << "\n";
        std::cout << "Адрес: " << array[i].street << ", " << array[i].houseNumber << "\n";
        std::cout << "Дата постановки на учет: " << array[i].registrationDate << "\n";
        std::cout << "------------------------------------------------------------\n";
    }
}

// Функция дополнения массива новыми записями
Market* addRecords(Market* array, int& size) {
    int n;
    std::cout << "Введите количество записей для добавления: ";
    std::cin >> n;
    std::cin.ignore();
    Market* newArray = new Market[size + n];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    for (int i = 0; i < n; i++) {
        std::cout << "Введите данные для новой записи " << size + i + 1 << ":\n";
        newArray[size + i].id = size + i + 1;
        std::cout << "Ф.И.О.: ";
        std::cin.getline(newArray[size + i].fullName, NAME_LENGTH);
        std::cout << "Улица: ";
        std::cin.getline(newArray[size + i].street, STREET_LENGTH);
        std::cout << "Номер дома: ";
        std::cin >> newArray[size + i].houseNumber;
        std::cin.ignore();
        std::cout << "Дата постановки на учет: ";
        std::cin.getline(newArray[size + i].registrationDate, DATE_LENGTH);
    }
    size += n;
    return newArray;
}

// Функция поиска записей по Ф.И.О.
void searchRecords(Market* array, int size, const char* searchName) {
    std::cout << "\nРезультаты поиска:\n";
    std::cout << "------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i].fullName, searchName) == 0) {
            std::cout << "Запись " << array[i].id << ":\n";
            std::cout << "Ф.И.О.: " << array[i].fullName << "\n";
            std::cout << "Адрес: " << array[i].street << ", " << array[i].houseNumber << "\n";
            std::cout << "Дата постановки на учет: " << array[i].registrationDate << "\n";
            std::cout << "------------------------------------------------------------\n";
        }
    }
}

// Функция удаления записи по ID
Market* deleteRecord(Market* array, int& size, int id) {
    Market* newArray = new Market[size - 1];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].id != id) {
            newArray[j++] = array[i];
        }
    }
    delete[] array;
    size--;
    return newArray;
}

// Функция изменения записи по ID
Market* modifyRecord(Market* array, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (array[i].id == id) {
            std::cout << "Введите новые данные для записи " << id << ":\n";
            std::cout << "Ф.И.О.: ";
            std::cin.getline(array[i].fullName, NAME_LENGTH);
            std::cout << "Улица: ";
            std::cin.getline(array[i].street, STREET_LENGTH);
            std::cout << "Номер дома: ";
            std::cin >> array[i].houseNumber;
            std::cin.ignore();
            std::cout << "Дата постановки на учет: ";
            std::cin.getline(array[i].registrationDate, DATE_LENGTH);
            break;
        }
    }
    return array;
}

// Функция сортировки массива по Ф.И.О.
void sortRecords(Market* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(array[j].fullName, array[j + 1].fullName) > 0) {
                Market temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Функция удаления дубликатов
void removeDuplicates(Market* array, int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(array[i].fullName, array[j].fullName) == 0 &&
                strcmp(array[i].street, array[j].street) == 0 &&
                array[i].houseNumber == array[j].houseNumber) {
                for (int k = j; k < size - 1; k++) {
                    array[k] = array[k + 1];
                }
                size--;
                j--;
            }
        }
    }
}

// Функция сохранения массива в текстовый файл
void saveToFile(Market* array, int size, const char* filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Не удалось открыть файл для записи\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        file << array[i].id << "\n";
        file << array[i].fullName << "\n";
        file << array[i].street << "\n";
        file << array[i].houseNumber << "\n";
        file << array[i].registrationDate << "\n";
    }
    file.close();
    std::cout << "Данные сохранены в файл " << filename << ".\n";
}

// Функция загрузки массива из текстового файла
void loadFromFile(Market*& array, int& size, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Не удалось открыть файл для чтения\n";
        return;
    }
    size = 0;
    Market temp;
    while (file >> temp.id) {
        file.ignore();
        file.getline(temp.fullName, NAME_LENGTH);
        file.getline(temp.street, STREET_LENGTH);
        file >> temp.houseNumber;
        file.ignore();
        file.getline(temp.registrationDate, DATE_LENGTH);
        array = (Market*)realloc(array, (size + 1) * sizeof(Market));
        array[size++] = temp;
    }
    file.close();
    std::cout << "Данные загружены из файла" << filename << ".\n";
}
