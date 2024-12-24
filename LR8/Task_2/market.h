#ifndef MARKET_H
#define MARKET_H

#define NAME_LENGTH 100
#define STREET_LENGTH 100
#define DATE_LENGTH 50

struct Market {
    int id;
    char fullName[NAME_LENGTH];
    char street[STREET_LENGTH];
    int houseNumber;
    char registrationDate[DATE_LENGTH];
};

Market* createArray(int& size, int choice);
void displayArray(Market* array, int size);
Market* addRecords(Market* array, int& size);
void searchRecords(Market* array, int size, const char* searchName);
Market* deleteRecord(Market* array, int& size, int id);
Market* modifyRecord(Market* array, int size, int id);
void sortRecords(Market* array, int size);
void removeDuplicates(Market* array, int& size);
void saveToFile(Market* array, int size, const char* filename);
void loadFromFile(Market*& array, int& size, const char* filename);

#endif
