#include "DynamicArray.h"
#include <iostream>

int main() {
    std::cout << "=== Задание 1: конструктор, сеттер, геттер, вывод ===" << std::endl;
    DynamicArray a(3);
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);
    a.print();                                   // [10, 20, 30]
    std::cout << "a.get(1) = " << a.get(1) << std::endl;
    a.set(5, 1);                                 // ошибка: индекс вне границ
    a.set(0, 150);                               // ошибка: значение больше 100
    a.get(5);                                    // ошибка: индекс вне границ

    std::cout << std::endl << "=== Задание 2: конструктор копирования ===" << std::endl;
    DynamicArray copy(a);
    copy.set(0, 99);                             // меняем только копию
    std::cout << "оригинал: ";
    a.print();                                   // [10, 20, 30] - не изменился
    std::cout << "копия:    ";
    copy.print();                                // [99, 20, 30]

    std::cout << std::endl << "=== Задание 3: добавление в конец ===" << std::endl;
    a.push_back(40);
    a.push_back(500);                            // ошибка: значение больше 100
    a.print();                                   // [10, 20, 30, 40]

    std::cout << std::endl << "=== Задание 4: сложение и вычитание ===" << std::endl;
    DynamicArray b(2);
    b.set(0, 1);
    b.set(1, 2);
    a.add(b);
    std::cout << "a + b: ";
    a.print();                                   // [11, 22, 30, 40]
    a.sub(b);
    std::cout << "a - b: ";
    a.print();                                   // [10, 20, 30, 40]

    return 0;
}
