#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "receipt.h"

// Функция создания массива квитанций
Receipt* createArray(int* size) {
    int choice;
    Receipt* array = NULL;
    *size = 0;
    while (1) {
        printf("Выберите способ ввода:\n");
        printf("1. Ввести заранее заданное количество квитанций\n");
        printf("2. Ввести до появления изделия с ценой больше 1000\n");
        printf("3. Ввести с диалогом о необходимости продолжать ввод\n");
        printf("Выбор: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            int n;
            printf("Введите количество квитанций для ввода: ");
            scanf("%d", &n);
            getchar();
            array = (Receipt*)malloc(n * sizeof(Receipt));
            if (!array) {
                printf("Ошибка выделения памяти\n");
                exit(1);
            }
            for (int i = 0; i < n; i++) {
                printf("Введите данные для квитанции %d:\n", i + 1);
                printf("Наименование изделия: ");
                fgets(array[i].nameOfEquipment, NAME_LENGTH, stdin);
                array[i].nameOfEquipment[strcspn(array[i].nameOfEquipment, "\n")] = '\0';
                printf("Дата приемки в ремонт: ");
                fgets(array[i].repairDate, DATE_LENGTH, stdin);
                array[i].repairDate[strcspn(array[i].repairDate, "\n")] = '\0';
                printf("Цена: ");
                scanf("%d", &array[i].price);
                getchar();
                printf("Состояние готовности заказа (1 выполнен, 0 не выполнен): ");
                scanf("%d", (int*)&array[i].isCompleted);
                getchar();
                printf("Выберите контактную информацию:\n1 Телефон\n2 Email\nВыбор: ");
                int contactChoice;
                scanf("%d", &contactChoice);
                getchar();
                if (contactChoice == 1) {
                    printf("Введите номер телефона: ");
                    fgets(array[i].contact.phoneNumber, CONTACT_LENGTH, stdin);
                    array[i].contact.phoneNumber[strcspn(array[i].contact.phoneNumber, "\n")] = '\0';
                } else {
                    printf("Введите Email: ");
                    fgets(array[i].contact.email, CONTACT_LENGTH, stdin);
                    array[i].contact.email[strcspn(array[i].contact.email, "\n")] = '\0';
                }
            }
            *size = n;
            break;
        } else if (choice == 2) {
            int n = 0;
            array = (Receipt*)malloc(sizeof(Receipt));
            if (!array) {
                printf("Ошибка выделения памяти\n");
                exit(1);
            }
            while (1) {
                printf("Введите данные для квитанции %d:\n", n + 1);
                printf("Наименование изделия: ");
                fgets(array[n].nameOfEquipment, NAME_LENGTH, stdin);
                array[n].nameOfEquipment[strcspn(array[n].nameOfEquipment, "\n")] = '\0';
                printf("Дата приемки в ремонт: ");
                fgets(array[n].repairDate, DATE_LENGTH, stdin);
                array[n].repairDate[strcspn(array[n].repairDate, "\n")] = '\0';
                printf("Цена: ");
                scanf("%d", &array[n].price);
                getchar();
                if (array[n].price > 1000) {
                    printf("Цена больше 1000\n");
                    n++;
                    break;
                }
                printf("Состояние готовности заказа (1 выполнен, 0 не выполнен): ");
                scanf("%d", (int*)&array[n].isCompleted);
                getchar();
                printf("Выберите контактную информацию:\n1. Телефон\n2. Email\nВыбор: ");
                int contactChoice;
                scanf("%d", &contactChoice);
                getchar();
                if (contactChoice == 1) {
                    printf("Введите номер телефона: ");
                    fgets(array[n].contact.phoneNumber, CONTACT_LENGTH, stdin);
                    array[n].contact.phoneNumber[strcspn(array[n].contact.phoneNumber, "\n")] = '\0';
                } else {
                    printf("Введите Email: ");
                    fgets(array[n].contact.email, CONTACT_LENGTH, stdin);
                    array[n].contact.email[strcspn(array[n].contact.email, "\n")] = '\0';
                }
                n++;
                array = (Receipt*)realloc(array, (n + 1) * sizeof(Receipt));
                if (!array) {
                    printf("Ошибка выделения памяти\n");
                    exit(1);
                }
            }
            *size = n;
            break;
        } else if (choice == 3) {
            int n = 0;
            array = (Receipt*)malloc(sizeof(Receipt));
            if (!array) {
                printf("Ошибка выделения памяти\n");
                exit(1);
            }
            while (1) {
                printf("Введите данные для квитанции %d:\n", n + 1);
                printf("Наименование изделия: ");
                fgets(array[n].nameOfEquipment, NAME_LENGTH, stdin);
                array[n].nameOfEquipment[strcspn(array[n].nameOfEquipment, "\n")] = '\0';
                printf("Дата приемки в ремонт: ");
                fgets(array[n].repairDate, DATE_LENGTH, stdin);
                array[n].repairDate[strcspn(array[n].repairDate, "\n")] = '\0';
                printf("Цена: ");
                scanf("%d", &array[n].price);
                getchar();
                printf("Состояние готовности заказа (1 выполнен, 0 не выполнен): ");
                scanf("%d", (int*)&array[n].isCompleted);
                getchar();
                printf("Выберите контактную информацию:\n1. Телефон\n2. Email\nВыбор: ");
                int contactChoice;
                scanf("%d", &contactChoice);
                getchar();
                if (contactChoice == 1) {
                    printf("Введите номер телефона: ");
                    fgets(array[n].contact.phoneNumber, CONTACT_LENGTH, stdin);
                    array[n].contact.phoneNumber[strcspn(array[n].contact.phoneNumber, "\n")] = '\0';
                } else {
                    printf("Введите Email: ");
                    fgets(array[n].contact.email, CONTACT_LENGTH, stdin);
                    array[n].contact.email[strcspn(array[n].contact.email, "\n")] = '\0';
                }
                n++;
                array = (Receipt*)realloc(array, (n + 1) * sizeof(Receipt));
                if (!array) {
                    printf("Ошибка выделения памяти\n");
                    exit(1);
                }
                char continueInput;
                printf("Продолжить ввод? (y/n): ");
                scanf("%c", &continueInput);
                getchar();
                if (continueInput == 'n') {
                    break;
                }
            }
            *size = n;
            break;
        } else {
            printf("Некорректный выбор. Попробуйте снова.\n");
        }
    }
    return array;
}

// Функция отображения массива квитанций
void displayArray(Receipt* array, int size) {
    printf("\nСписок квитанций:\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("Квитанция %d:\n", i + 1);
        printf("Наименование изделия: %s\n", array[i].nameOfEquipment);
        printf("Дата приемки в ремонт: %s\n", array[i].repairDate);
        printf("Цена: %d\n", array[i].price);
        printf("Состояние готовности заказа: %s\n", array[i].isCompleted ? "выполнен" : "не выполнен");
        if (strlen(array[i].contact.phoneNumber) > 0) {
            printf("Телефон: %s\n", array[i].contact.phoneNumber);
        } else {
            printf("Email: %s\n", array[i].contact.email);
        }
        printf("------------------------------------------------------------\n");
    }
}

// Функция дополнения массива квитанций
Receipt* addReceipts(Receipt* array, int* size) {
    int n;
    printf("Сколько квитанций хотите добавить: ");
    scanf("%d", &n);
    getchar();
    array = (Receipt*)realloc(array, (*size + n) * sizeof(Receipt));
    if (!array) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        printf("Введите данные для новой квитанции %d:\n", *size + 1);
        printf("Наименование изделия: ");
        fgets(array[*size].nameOfEquipment, NAME_LENGTH, stdin);
        array[*size].nameOfEquipment[strcspn(array[*size].nameOfEquipment, "\n")] = '\0';
        printf("Дата приемки в ремонт: ");
        fgets(array[*size].repairDate, DATE_LENGTH, stdin);
        array[*size].repairDate[strcspn(array[*size].repairDate, "\n")] = '\0';
        printf("Цена: ");
        scanf("%d", &array[*size].price);
        getchar();
        printf("Состояние готовности заказа (1 выполнен, 0 не выполнен): ");
        scanf("%d", (int*)&array[*size].isCompleted);
        getchar();
        printf("Выберите контактную информацию:\n1. Телефон\n2. Email\nВыбор: ");
        int contactChoice;
        scanf("%d", &contactChoice);
        getchar();
        if (contactChoice == 1) {
            printf("Введите номер телефона: ");
            fgets(array[*size].contact.phoneNumber, CONTACT_LENGTH, stdin);
            array[*size].contact.phoneNumber[strcspn(array[*size].contact.phoneNumber, "\n")] = '\0';
        } else {
            printf("Введите Email: ");
            fgets(array[*size].contact.email, CONTACT_LENGTH, stdin);
            array[*size].contact.email[strcspn(array[*size].contact.email, "\n")] = '\0';
        }
        (*size)++;
    }
    return array;
}

// Функция поиска квитанций по признаку
void searchReceipts(Receipt* array, int size) {
    char searchName[NAME_LENGTH];
    printf("Введите наименование изделия для поиска: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    printf("\nРезультаты поиска:\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i].nameOfEquipment, searchName) == 0) {
            printf("Квитанция %d:\n", i + 1);
            printf("Наименование изделия: %s\n", array[i].nameOfEquipment);
            printf("Дата приемки в ремонт: %s\n", array[i].repairDate);
            printf("Цена: %d\n", array[i].price);
            printf("Состояние готовности заказа: %s\n", array[i].isCompleted ? "выполнен" : "не выполнен");
            if (strlen(array[i].contact.phoneNumber) > 0) {
                printf("Телефон: %s\n", array[i].contact.phoneNumber);
            } else {
                printf("Email: %s\n", array[i].contact.email);
            }
            printf("------------------------------------------------------------\n");
        }
    }
}

// Функция удаления квитанции
Receipt* deleteReceipt(Receipt* array, int* size) {
    if (*size == 0) {
        printf("Массив пуст\n");
        return array;
    }
    int index;
    printf("Введите индекс квитанции для удаления (1 - %d): ", *size);
    scanf("%d", &index);
    getchar();
    if (index < 1 || index > *size) {
        printf("Некорректный индекс\n");
        return array;
    }
    for (int i = index - 1; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }
    (*size)--;
    array = (Receipt*)realloc(array, (*size) * sizeof(Receipt));
    printf("Квитанция удалена\n");
    return array;
}

// Функция изменения данных квитанции
Receipt* modifyReceipt(Receipt* array, int size) {
    if (size == 0) {
        printf("Массив пуст\n");
        return array;
    }
    int index;
    printf("Введите индекс квитанции для изменения (1 - %d): ", size);
    scanf("%d", &index);
    getchar();
    if (index < 1 || index > size) {
        printf("Некорректный индекс\n");
        return array;
    }
    int i = index - 1;
    printf("Введите новые данные для квитанции %d:\n", index);
    printf("Наименование изделия: ");
    fgets(array[i].nameOfEquipment, NAME_LENGTH, stdin);
    array[i].nameOfEquipment[strcspn(array[i].nameOfEquipment, "\n")] = '\0';
    printf("Дата приемки в ремонт: ");
    fgets(array[i].repairDate, DATE_LENGTH, stdin);
    array[i].repairDate[strcspn(array[i].repairDate, "\n")] = '\0';
    printf("Цена: ");
    scanf("%d", &array[i].price);
    getchar();
    printf("Состояние готовности заказа (1 выполнен, 0 не выполнен): ");
    scanf("%d", (int*)&array[i].isCompleted);
    getchar();
    printf("Выберите контактную информацию:\n1. Телефон\n2. Email\nВыбор: ");
    int contactChoice;
    scanf("%d", &contactChoice);
    getchar();
    if (contactChoice == 1) {
        printf("Введите номер телефона: ");
        fgets(array[i].contact.phoneNumber, CONTACT_LENGTH, stdin);
        array[i].contact.phoneNumber[strcspn(array[i].contact.phoneNumber, "\n")] = '\0';
        array[i].contact.email[0] = '\0';
    } else {
        printf("Введите Email: ");
        fgets(array[i].contact.email, CONTACT_LENGTH, stdin);
        array[i].contact.email[strcspn(array[i].contact.email, "\n")] = '\0';
        array[i].contact.phoneNumber[0] = '\0';
    }
    printf("Квитанция изменена\n");
    return array;
}

// Функция сортировки массива квитанций методом обмена (по убыванию)
void sortReceipts(Receipt* array, int size) {
    if (size < 2) {
        printf("Для сортировки нужно больше 2-ух квитанций\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].isCompleted < array[j + 1].isCompleted) {
                Receipt temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("Квитанции отсортированы по готовности заказа\n");
}

// Функция сохранения массива в файл
void saveToFile(Receipt* array, int size, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Не удалось открыть файл для записи\n");
        return;
    }
    fwrite(&size, sizeof(int), 1, file);
    fwrite(array, sizeof(Receipt), size, file);
    fclose(file);
    printf("Данные сохранены в файл %s.\n", filename);
}

// Функция загрузки массива из файла
void loadFromFile(Receipt** array, int* size, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Не удалось открыть файл для чтения\n");
        return;
    }
    fread(size, sizeof(int), 1, file);
    *array = (Receipt*)malloc(*size * sizeof(Receipt));
    if (!*array) {
        printf("Ошибка выделения памяти\n");
        fclose(file);
        exit(1);
    }
    fread(*array, sizeof(Receipt), *size, file);
    fclose(file);
    printf("Данные загружены из файла %s.\n", filename);
}

// Функция обновления конкретной квитанции в файле
void updateReceiptInFile(const char* filename, int index, Receipt receipt) {
    FILE* file = fopen(filename, "rb+");
    if (!file) {
        printf("Не удалось открыть файл для обновления\n");
        return;
    }
    fseek(file, sizeof(int) + index * sizeof(Receipt), SEEK_SET);
    fwrite(&receipt, sizeof(Receipt), 1, file);
    fclose(file);
    printf("Данные квитанции обновлены в файле\n");
}



























