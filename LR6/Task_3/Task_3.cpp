#include <iostream>
#include <cstring>

bool areAnagrams(const char* str1, const char* str2);

int main() {
    char str1[100], str2[100];

    std::cout << "введите первую строку: ";
    std::cin.getline(str1, 100);
    std::cout << "введите вторую строку: ";
    std::cin.getline(str2, 100);

    if (areAnagrams(str1, str2)) {
        std::cout << "cтроки являются анаграммами." << std::endl;
    } else {
        std::cout << "cтроки не являются анаграммами." << std::endl;
    }

    std::cout << std::endl;
    getchar();
    return 0;
}

bool areAnagrams(const char* str1, const char* str2) {
    int count1[256] = {0};
    int count2[256] = {0};

    for (int i = 0; str1[i] != '\0'; ++i) {
        count1[static_cast<unsigned char>(str1[i])]++;
    }

    for (int i = 0; str2[i] != '\0'; ++i) {
        count2[static_cast<unsigned char>(str2[i])]++;
    }


    for (int i = 0; i < 256; ++i) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }

    return true;
}
