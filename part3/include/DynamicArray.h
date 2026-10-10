#pragma once
#include <iostream>
#include <stdexcept>     
#include <typeinfo>      
#include <type_traits>   
#include <cmath>        

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;
    void checkValue(T value) {
        if constexpr (std::is_integral_v<T>) {
            long long number =value;      
            if (number < -100||number >100) {
                throw std::invalid_argument("Значение не входит в промежуток от -100 до 100");
            }
        }
    }

public:
    DynamicArray(int arraySize){
        size =arraySize;
        data =new T[size];
        for (int i =0; i <size;i++){
            data[i] = T();             
        }
    }

    DynamicArray(const DynamicArray& other){
        size =other.size;
        data =new T[size];
        for (int i =0; i<size; i++) {
            data[i] =other.data[i];
        }
    }

    ~DynamicArray() {
        delete[] data;
    }

    int getSize() {
        return size;
    }

    void set(int index, T value) {
        if (index <0 ||index >=size) {
            throw std::out_of_range("Индекс выходит за границы массива");
        }
        checkValue(value);
        data[index] = value;
    }

    T get(int index){
        if (index <0 || index>= size) {
            throw std::out_of_range("Индекс выходит за границы массива");
        }
        return data[index];
    }

    void push_back(T value) {
        checkValue(value);
        T* newData =new T[size+1];
        for (int i = 0; i < size;i++) {
            newData[i] =data[i];
        }
        newData[size] =value;
        delete[] data;
        data = newData;
        size = size + 1;
    }

    void add(const DynamicArray& other) {
        int count = size;
        if (other.size < count) {
            count = other.size;
        }
        for (int i = 0; i < count; i++) {
            data[i] = data[i] + other.data[i];
        }
    }

    void sub(const DynamicArray& other){
        int count = size;
        if (other.size <count){
            count =other.size;
        }
        for (int i = 0; i < count; i++) {
            data[i] =data[i] -other.data[i];
        }
    }

    double distance(DynamicArray& other) {
        if constexpr (std::is_arithmetic_v<T>) {
            if (size != other.size) {
                throw std::invalid_argument("Размеры массивов должны быть одинаковыми");
            }
            double sum = 0;
            for (int i=0; i<size;i++) {
                double difference =(double)data[i]-(double)other.data[i];
                sum = sum +difference*difference;
            }
            return std::sqrt(sum);
        } else {
            throw std::bad_typeid();
        }
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, DynamicArray<T>& array){
    out << "[";
    for (int i=0; i <array.getSize();i++){
        out << array.get(i);
        if (i < array.getSize()-1){
            out << ", ";
        }
    }
    out << "]";
    return out;
}
