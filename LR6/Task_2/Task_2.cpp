#include <iostream>
#include <cstring>

bool isUnique(const char* word, char words[][100], int count);

int main() {
    std::cout << "введите текст: ";

    char textstr[1000];
    std::cin.getline(textstr, 1000);
    std::cout << "исходный текст: " << textstr << '\n';

    char words[1000][100]; // массив уникальных слов
    int wordCount = 0;
    char word[100] = "";

    for (int i = 0; textstr[i] != '\0'; ++i) {
        if (textstr[i] == ' ') {

            if (strlen(word) > 0 && word[0] == word[strlen(word) - 1] && isUnique(word, words, wordCount)) {
                strcpy(words[wordCount++], word);
            }

            word[0] = '\0';

        } else {
            
            int len = strlen(word);
            word[len] = textstr[i];
            word[len + 1] = '\0';

        }
    }
    if (strlen(word) > 0 && word[0] == word[strlen(word) - 1] && isUnique(word, words, wordCount)) {
        strcpy(words[wordCount++], word);
    }

    std::cout << "cлова, у которых первая и последняя буквы совпадают: ";
    for (int i = 0; i < wordCount; ++i) {
        std::cout << words[i] << " ";
    }

    std::cout << std::endl;
    getchar();
    return 0;
}

bool isUnique(const char* word, char words[][100], int count) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(words[i], word) == 0) {
            return false;
        }
    }
    return true;
}
