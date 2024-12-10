#include <iostream>
#include <limits>
#include <cstring>
void showMenu();
class labWork {
public:
    int task1(); 
    int task2();  
    int task3();  
};


int main() {

    labWork laba;
    int choice;
    showMenu();

    std::cin >> choice;

        while (std::cin.fail() || choice != 0 && choice != 1 && choice != 2 && choice != 3) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Некорректный ввод. Пожалуйста, попробуйте еще раз: ";
            std::cin >> choice;
        }

    switch (choice) {
        case 1:
            std::cout << "Task_1: " << laba.task1() << std::endl;
            break;
        case 2:
            std::cout << "Task_2: " << laba.task2() << std::endl;
            break;
        case 3:
            std::cout << "Task_3: " << laba.task3() << std::endl;
            break;
        case 0:
            break;
        default:
            break;
    }

    return 0;
}

int labWork::task1() {

    const int MAX_LENGTH = 80;
    char input[MAX_LENGTH + 1];

    int index = 0;
    int round = 0; // ()
    int square = 0; // []
    int curly = 0; // {}

    char trex[112];
    std::cin.getline(trex, 112);

    std::cout << "введите текст: ";

    while (true) {
        char ch = getchar();
        if (ch == '\n') {
            input[index] = '\0';
            if (index == 0 || ch == '\n') {
                break;
            }
        } else {
            if (index < MAX_LENGTH) {
                input[index++] = ch;
                switch (ch) {
                    case '(': round++; break;
                    case ')': round++; break;
                    case '[': square++; break;
                    case ']': square++; break;
                    case '{': curly++; break;
                    case '}': curly++; break;
                    default: break;
                }
            } else {
                std::cerr << "ошибка: строка превышает 80 символов." << std::endl;
                while ((ch = getchar()) != '\n');
            }
        }
    }

    std::cout << "исходный текст: ";
    for (int i = 0; i < index; i++) {
        std::cout << input[i] ;
    }
    std::cout << std::endl;
    std::cout << "количество круглых скобок: " << round << std::endl;
    std::cout << "количество квадратных скобок: " << square << std::endl;
    std::cout << "количество фигурных скобок: " << curly << std::endl;
    getchar();
    return 0;
}

int labWork::task2() {

    char trex[112];
    std::cin.getline(trex, 112);

    std::cout << "введите текст: ";

    char textstr[1000];
    std::cin.getline(textstr, 1000);
    std::cout << "исходный текст: " << textstr << '\n';

    char words[1000][100]; // массив уникальных слов
    int wordCount = 0;
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

    std::cout << "cлова, у которых первая и последняя буквы совпадают: ";
    for (int i = 0; i < wordCount; ++i) {
        std::cout << words[i] << " ";
    }

    std::cout << std::endl;
    getchar();
    return 0;
}

int labWork::task3() {
    
    char trex[112];
    std::cin.getline(trex, 112);
    
    char str1[100], str2[100];

    std::cout << "введите первую строку: ";
    std::cin.getline(str1, 100);
    std::cout << "введите вторую строку: ";
    std::cin.getline(str2, 100);

    int count1[256] = {0};
    int count2[256] = {0};

    for (int i = 0; str1[i] != '\0'; ++i) {
        count1[static_cast<unsigned char>(str1[i])]++;
    }

    for (int i = 0; str2[i] != '\0'; ++i) {
        count2[static_cast<unsigned char>(str2[i])]++;
    }

    bool areAnagrams = true;
    for (int i = 0; i < 256; ++i) {
        if (count1[i] != count2[i]) {
            areAnagrams = false;
            break;
        }
    }

    if (areAnagrams) {
        std::cout << "cтроки являются анаграммами." << std::endl;
    } else {
        std::cout << "cтроки не являются анаграммами." << std::endl;
    }

    std::cout << std::endl;
    getchar();
    return 0;
}

void showMenu(){
    std::cout << "================================= \n";
    std::cout << "Задание выполнено: мной           \n"; 
    std::cout << "Номер варианта: йоу               \n"; 
    std::cout << "================================= \n";
    std::cout << "         Меню программы           \n";
    std::cout << " 1. Задание 1                     \n";
    std::cout << " 2. Задание 2                     \n";
    std::cout << " 3. Задание 3                     \n";
    std::cout << " 0. Выйти из программы            \n";
    std::cout << "================================= \n";
    std::cout << "Выберите действие: ";
}