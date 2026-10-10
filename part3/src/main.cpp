#include "DynamicArray.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>

int main() {
    std::cout << "=== Массив int ===" << std::endl;
    DynamicArray<int> a(3);
    a.set(0, 1);
    a.set(1, 2);
    a.set(2, 3);
    DynamicArray<int> b(3);
    b.set(0, 4);
    b.set(1, 6);
    b.set(2, 3);
    std::cout << "a = " << a << std::endl;          
    std::cout << "b = " << b << std::endl;

    try {
        a.set(0, 500);                              
    } catch (const std::invalid_argument& e) {
        std::cout << "invalid_argument: " << e.what() << std::endl;
    }

    std::cout << "Расстояние между a и b = " << a.distance(b) << std::endl;  

    DynamicArray<int> c(2);
    try {
        a.distance(c);                            
    } catch (const std::invalid_argument& e) {
        std::cout << "invalid_argument: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Массив double ===" << std::endl;
    DynamicArray<double> d1(2);
    DynamicArray<double> d2(2);
    d1.set(0, 1000.5);                              
    d1.set(1, 0.0);
    d2.set(0, 1000.5);
    d2.set(1, 2.0);
    std::cout << "d1 = " << d1 << ", d2 = " << d2 << std::endl;
    std::cout << "Расстояние = " << d1.distance(d2) << std::endl;          

    // ---------- Нечисловой тип: string ----------
    std::cout << std::endl << "=== Массив string ===" << std::endl;
    DynamicArray<std::string> s1(2);
    DynamicArray<std::string> s2(2);
    s1.set(0, "hello");
    s1.set(1, "world");
    s2.set(0, "foo");
    s2.set(1, "bar");
    s1.push_back("!");
    std::cout << "s1 = " << s1 << std::endl;
    try {
        s1.distance(s2);                           
    } catch (const std::bad_typeid& e) {
        std::cout << "bad_typeid: для строк расстояние посчитать нельзя" << std::endl;
    }

    return 0;
}
