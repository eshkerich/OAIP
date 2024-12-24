#ifndef RECEIPT_H
#define RECEIPT_H

#define NAME_LENGTH 100
#define DATE_LENGTH 50
#define CONTACT_LENGTH 50

typedef struct {
    bool isCompleted;
    int price;
    char nameOfEquipment[NAME_LENGTH];
    char repairDate[DATE_LENGTH];
    union {
        char phoneNumber[CONTACT_LENGTH];
        char email[CONTACT_LENGTH];
    } contact;
} Receipt;

Receipt* createArray(int* size);
void displayArray(Receipt* array, int size);
Receipt* addReceipts(Receipt* array, int* size);
void searchReceipts(Receipt* array, int size);
Receipt* deleteReceipt(Receipt* array, int* size);
Receipt* modifyReceipt(Receipt* array, int size);
void sortReceipts(Receipt* array, int size);
void saveToFile(Receipt* array, int size, const char* filename);
void loadFromFile(Receipt** array, int* size, const char* filename);
void updateReceiptInFile(const char* filename, int index, Receipt receipt);

#endif
