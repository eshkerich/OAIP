#include <iostream>
#include <cmath>

int main() { 
    double start, end, step; 
 // Задаем исходное значение переменной 
    std::cout << "Введите начальное значение x: "; 
    std::cin >> start; 
 // Задаем конечно значение переменной
    std::cout << "Введите конечное значение x: "; 
    std::cin >> end; 
 // Задаем шаг, с которым с которым будет изменяться аргумент
    std::cout << "Введите шаг: "; 
    std::cin >> step; 

 for (double x = start; x <= end; x += step) { 
 // функция y = sin(x) 
    double y = sin(x);   
 // Выводим значения функции для каждого аргумента (x | y)  
    std::cout << x << " | " << y << std::endl;
} 

 return 0; 
}
