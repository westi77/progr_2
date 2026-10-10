#pragma once

//Часть 1
class DynamicArray {
private:
    int* data;     
    int size;       
public:
    DynamicArray(int arraySize);                    
    DynamicArray(const DynamicArray& other);        
    ~DynamicArray();                               

    int getSize();
    void print();                                  
    bool set(int index,int  value);                
    int get(int  index);                             
    void push_back(int value);                     
    void  add(const DynamicArray& other);           
    void sub(const DynamicArray&  other);           
};
