#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray(int arraySize) {
    size=arraySize;
    data =new int[size];
    for (int i= 0; i<size;i++) {
        data[i]=0;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other){
    size =other.size;
    data =new  int[size];
    for (int i=0; i<size;i++){
        data[i] =other.data[i];
    }
}

DynamicArray::~DynamicArray(){
    delete[]  data;
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
    std::cout <<"]"<< std::endl;
}

bool DynamicArray::set(int index,int value){
    if (index <0 ||index>= size){
        std::cout << "Ошибка: индекс "<<index << " выходит за границы массива" << std::endl;
        return false;
    }
    if (value <-100 || value >100) {
        std::cout<<"Ошибка:значение" <<value << " не входит в промежуток от -100 до 100" << std::endl;
        return false;
    }
    data[index] = value;
    return true;
}

int DynamicArray::get(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Ошибка: индекс " << index << " выходит за границы массива" << std::endl;
        return 0;
    }
    return data[index];
}

void DynamicArray::push_back(int value){
    if (value < -100 || value > 100) {
        std::cout << "Ошибка: значение "<< value << " не входит в промежуток от -100 до 100" << std::endl;
        return;
    }
    int* newData =new int[size+1];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    newData[size] = value;
    delete[] data;
    data = newData;
    size = size + 1;
}

void DynamicArray::add(const DynamicArray& other){
    int count = size;
    if (other.size < count){
        count = other.size;
    }
    for (int i= 0;i<count; i++){
        data[i] = data[i] + other.data[i];
    }
}
void DynamicArray::sub(const DynamicArray& other) {
    int count =size;
    if (other.size <count) {
        count = other.size;
    }
    for (int i =0; i <count;i++) {
        data[i] = data[i]- other.data[i];
    }
}
