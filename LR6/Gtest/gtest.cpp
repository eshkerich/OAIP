#include <gtest/gtest.h>
#include <cstring>
#include <limits>
#include <iostream>

// Функция для подсчета скобок
void countBrackets(const char* input, int& round, int& square, int& curly) {
    round = square = curly = 0;
    int index = 0;
    while (input[index] != '\0') {
        switch (input[index]) {
            case '(': round++; break;
            case ')': round++; break;
            case '[': square++; break;
            case ']': square++; break;
            case '{': curly++; break;
            case '}': curly++; break;
            default: break;
        }
        index++;
    }
}

// Функция для поиска уникальных слов, у которых первая и последняя буквы совпадают
void findUniqueWords(const char* textstr, char words[][100], int& wordCount) {
    wordCount = 0;
    char word[100] = "";
    for (int i = 0; textstr[i] != '\0'; ++i) {
        if (textstr[i] == ' ') {
            bool unique = true;
            for (int j = 0; j < wordCount; ++j) {
                if (strcmp(words[j], word) == 0) {
                    unique = false;
                    break;
                }
            }
            if (strlen(word) > 0 && word[0] == word[strlen(word) - 1] && unique) {
                strcpy(words[wordCount++], word);
            }
            word[0] = '\0';
        } else {
            int len = strlen(word);
            word[len] = textstr[i];
            word[len + 1] = '\0';
        }
    }
    bool unique = true;
    for (int j = 0; j < wordCount; ++j) {
        if (strcmp(words[j], word) == 0) {
            unique = false;
            break;
        }
    }
    if (strlen(word) > 0 && word[0] == word[strlen(word) - 1] && unique) {
        strcpy(words[wordCount++], word);
    }
}

// Функция для проверки, являются ли строки анаграммами
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

TEST(LabWorkTest, CountBrackets) {
    int round, square, curly;

    // Краевые тесты
    countBrackets("()", round, square, curly);
    EXPECT_EQ(round, 2);
    EXPECT_EQ(square, 0);
    EXPECT_EQ(curly, 0);

    countBrackets("[]", round, square, curly);
    EXPECT_EQ(round, 0);
    EXPECT_EQ(square, 2);
    EXPECT_EQ(curly, 0);

    // Обычные тесты
    countBrackets("({[]})", round, square, curly);
    EXPECT_EQ(round, 2);
    EXPECT_EQ(square, 2);
    EXPECT_EQ(curly, 2);

    countBrackets("eshkere", round, square, curly);
    EXPECT_EQ(round, 0);
    EXPECT_EQ(square, 0);
    EXPECT_EQ(curly, 0);
}

TEST(LabWorkTest, FindUniqueWords) {
    char words[1000][100];
    int wordCount;

    // Краевые тесты
    findUniqueWords("a a", words, wordCount);
    EXPECT_EQ(wordCount, 1);
    EXPECT_STREQ(words[0], "a");

    findUniqueWords("aba aba", words, wordCount);
    EXPECT_EQ(wordCount, 1);
    EXPECT_STREQ(words[0], "aba");

    // Обычные тесты
    findUniqueWords("aba cdc aba", words, wordCount);
    EXPECT_EQ(wordCount, 2);
    EXPECT_STREQ(words[0], "aba");
    EXPECT_STREQ(words[1], "cdc");

    findUniqueWords("hello world", words, wordCount);
    EXPECT_EQ(wordCount, 0);
}

TEST(LabWorkTest, AreAnagrams) {
    // Краевые тесты
    EXPECT_TRUE(areAnagrams("a", "a"));
    EXPECT_FALSE(areAnagrams("a", "b"));

    // Обычные тесты
    EXPECT_TRUE(areAnagrams("listen", "silent"));
    EXPECT_FALSE(areAnagrams("hello", "world"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
