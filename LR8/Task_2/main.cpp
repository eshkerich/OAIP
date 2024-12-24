#include <iostream>
#include "market.h"

int main() {
    Market* records = nullptr;
    int size = 0;
    int choice;
    const char* filename = "records.txt";

    while (true) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Создать массив записей\n";
        std::cout << "2. Просмотреть список записей\n";
        std::cout << "3. Добавить записи\n";
        std::cout << "4. Поиск записей по Ф.И.О.\n";
        std::cout << "5. Удалить запись по ID\n";
        std::cout << "6. Изменить запись по ID\n";
        std::cout << "7. Отсортировать записи по Ф.И.О.\n";
        std::cout << "8. Удалить дубликаты\n";
        std::cout << "9. Сохранить данные в файл\n";
        std::cout << "10. Загрузить данные из файла\n";
        std::cout << "11. Выход\n";
        std::cout << "Выбор: ";
        std::cin >> choice;
        std::cin.ignore(); // Очистка буфера

        switch (choice) {
            case 1:
                if (records != nullptr) {
                    delete[] records;
                }
                std::cout << "Выберите способ ввода:\n";
                std::cout << "1. Ввести заранее заданное количество структур\n";
                std::cout << "2. Ввести до появления структуры с номером дома больше 50\n";
                std::cout << "3. Ввести с диалогом о необходимости продолжать ввод\n";
                std::cout << "Выбор: ";
                std::cin >> choice;
                std::cin.ignore();
                records = createArray(size, choice);
                break;
            case 2:
                if (records == nullptr || size == 0) {
                    std::cout << "Сначала создайте массив записей\n";
                } else {
                    displayArray(records, size);
                }
                break;
            case 3:
                if (records == nullptr) {
                    std::cout << "Сначала создайте массив записей\n";
                } else {
                    records = addRecords(records, size);
                }
                break;
            case 4:
                if (records == nullptr || size == 0) {
                    std::cout << "Массив пуст\n";
                } else {
                    char searchName[NAME_LENGTH];
                    std::cout << "Введите Ф.И.О. для поиска: ";
                    std::cin.ignore();
                    std::cin.getline(searchName, NAME_LENGTH);
                    searchRecords(records, size, searchName);
                }
                break;
            case 5:
                if (records == nullptr || size == 0) {
                    std::cout << "Массив пуст\n";
                } else {
                    int id;
                    std::cout << "Введите ID записи для удаления: ";
                    std::cin >> id;
                    records = deleteRecord(records, size, id);
                }
                break;
            case 6:
                if (records == nullptr || size == 0) {
                    std::cout << "Массив пуст\n";
                } else {
                    int id;
                    std::cout << "Введите ID записи для изменения: ";
                    std::cin >> id;
                    records = modifyRecord(records, size, id);
                }
                break;
            case 7:
                if (records == nullptr || size == 0) {
                    std::cout << "Массив пуст\n";
                } else {
                    sortRecords(records, size);
                }
                break;
            case 8:
                if (records == nullptr || size == 0) {
                    std::cout << "Массив пуст\n";
                } else {
                    removeDuplicates(records, size);
                }
                break;
            case 9:
                if (records == nullptr || size == 0) {
                    std::cout << "Массив пуст\n";
                } else {
                    saveToFile(records, size, filename);
                }
                break;
            case 10:
                if (records != nullptr) {
                    delete[] records;
                }
                records = nullptr;
                loadFromFile(records, size, filename);
                break;
            case 11:
                if (records != nullptr) {
                    delete[] records;
                }
                std::cout << "Выход из программы\n";
                return 0;
            default:
                std::cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }
}
