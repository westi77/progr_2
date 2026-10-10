#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>
#include <new>

int main() {
    DynamicArray a(3);
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);
    std::cout << "Массив: ";
    a.print();

    std::cout << std::endl << "--- std::out_of_range ---" << std::endl;
    try {
        a.set(10, 1);
    } catch (const std::out_of_range& e) {
        std::cout << "Поймано в set: " << e.what() << std::endl;
    }
    try {
        a.get(10);
    } catch (const std::out_of_range& e) {
        std::cout << "Поймано в get: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- std::invalid_argument ---" << std::endl;
    try {
        a.set(0, 150);
    } catch (const std::invalid_argument& e) {
        std::cout << "Поймано в set: " << e.what() << std::endl;
    }
    try {
        a.push_back(-500);
    } catch (const std::invalid_argument& e) {
        std::cout << "Поймано в push_back: " << e.what() << std::endl;
    }
    std::cout << std::endl << "--- std::bad_alloc ---" << std::endl;
    try {
        DynamicArray huge(-1);
    } catch (const std::bad_alloc& e) {
        std::cout << "Поймано в конструкторе: не удалось выделить память" << std::endl;
    }

    std::cout << std::endl << "Массив после всех ошибок остался целым: ";
    a.print();
    return 0;
}
