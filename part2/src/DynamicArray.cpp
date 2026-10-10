#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>   
#include <new>        

DynamicArray::DynamicArray(int arraySize) {
    size = arraySize;
    data = new int[size];
    for (int i =0; i<size;i++){
        data[i]=0;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    size=other.size;
    data= new int[size];
    for (int i=0; i<size;i++){
        data[i]=other.data[i];
    }
}

DynamicArray::~DynamicArray(){
    delete[] data;
}

int DynamicArray::getSize(){
    return size;
}

void DynamicArray::print() {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << data[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout <<"]"<<std::endl;
}

void DynamicArray::set(int index, int value){
    if (index <0|| index >=size) {
        throw std::out_of_range("Индекс выходит за границы массива");
    }
    if (value <-100 || value > 100) {
        throw std::invalid_argument("Значение не входит в промежуток от -100 до 100");
    }
    data[index] = value;
}

int DynamicArray::get(int index) {
    if (index < 0||index >= size) {
        throw std::out_of_range("Индекс выходит за границы массива");
    }
    return data[index];
}

void DynamicArray::push_back(int value) {
    if (value < -100 || value > 100) {
        throw std::invalid_argument("Значение не входит в промежуток от -100 до 100");
    }
    int* newData = new int[size + 1];   
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    newData[size]=value;
    delete[] data;
    data =newData;
    size =size+1;
}

void DynamicArray::add(const DynamicArray& other){
    int count = size;
    if (other.size < count) {
        count = other.size;
    }
    for (int i = 0; i < count; i++) {
        data[i] = data[i] + other.data[i];
    }
}

void DynamicArray::sub(const DynamicArray& other) {
    int count =size;
    if (other.size <count) {
        count = other.size;
    }
    for (int i=0; i < count; i++) {
        data[i] = data[i] - other.data[i];
    }
}
