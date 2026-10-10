#pragma once

// Часть 2. Тот же класс, но ошибки теперь выбрасываются как исключения:
//   std::out_of_range     - индекс вне границ массива
//   std::invalid_argument - значение не в промежутке от -100 до 100
//   std::bad_alloc        - не удалось выделить память
class DynamicArray {
private:
    int* data;      // указатель на сами числа
    int size;       // сколько чисел в массиве

public:
    DynamicArray(int arraySize);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    int getSize();
    void print();
    void set(int index, int value);                 // теперь ничего не возвращает, при ошибке бросает исключение
    int get(int index);
    void push_back(int value);
    void add(const DynamicArray& other);
    void sub(const DynamicArray& other);
};
