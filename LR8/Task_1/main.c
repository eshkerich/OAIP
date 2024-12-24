#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "receipt.h"

int main() {
    Receipt* receipts = NULL;
    int size = 0;
    int choice;
    const char* filename = "receipts.dat";

    while (1) {
        printf("\nМеню:\n");
        printf("1. Создать массив квитанций\n");
        printf("2. Просмотреть список квитанций\n");
        printf("3. Добавить квитанции\n");
        printf("4. Поиск квитанций по признаку\n");
        printf("5. Удалить квитанцию\n");
        printf("6. Изменить данные квитанции\n");
        printf("7. Отсортировать квитанции\n");
        printf("8. Сохранить данные в файл\n");
        printf("9. Загрузить данные из файла\n");
        printf("10. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                if (receipts != NULL) {
                    free(receipts);
                }
                receipts = createArray(&size);
                break;
            case 2:
                if (receipts == NULL || size == 0) {
                    printf("Сначала создайте массив квитанций\n");
                } else {
                    displayArray(receipts, size);
                }
                break;
            case 3:
                if (receipts == NULL) {
                    printf("Сначала создайте массив квитанций\n");
                } else {
                    receipts = addReceipts(receipts, &size);
                }
                break;
            case 4:
                if (receipts == NULL || size == 0) {
                    printf("Массив пуст\n");
                } else {
                    searchReceipts(receipts, size);
                }
                break;
            case 5:
                if (receipts == NULL || size == 0) {
                    printf("Массив пуст\n");
                } else {
                    receipts = deleteReceipt(receipts, &size);
                }
                break;
            case 6:
                if (receipts == NULL || size == 0) {
                    printf("Массив пуст\n");
                } else {
                    receipts = modifyReceipt(receipts, size);
                }
                break;
            case 7:
                if (receipts == NULL || size == 0) {
                    printf("Массив пуст\n");
                } else {
                    sortReceipts(receipts, size);
                }
                break;
            case 8:
                if (receipts == NULL || size == 0) {
                    printf("Массив пуст\n");
                } else {
                    saveToFile(receipts, size, filename);
                }
                break;
            case 9:
                if (receipts != NULL) {
                    free(receipts);
                }
                loadFromFile(&receipts, &size, filename);
                break;
            case 10:
                if (receipts != NULL) {
                    free(receipts);
                }
                printf("Выход из программы\n");
                exit(0);
            default:
                printf("Некорректный выбор. Попробуйте снова.\n");
        }
    }
    return 0;
}
