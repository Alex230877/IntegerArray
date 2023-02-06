#pragma once
#include <iostream>

class IntArray 
{
private:
    int size;
    int* ptr;

public:
    IntArray() = default;

    IntArray(int length); 

    IntArray(const IntArray& other);

    ~IntArray();

    const IntArray& operator=(const IntArray&);

    bool operator==(const IntArray&) const;

    bool operator!=(const IntArray& right) const;

    int& operator[](int);

    const int& operator[](int) const;

    int get_size() const; 

    void erase(); 

    void resize(int newLength); 

    void insert(int value, int index);  

    void remove(int index); 

    void push_front(int value); 

    void push_back(int value);  

    int get_value(const int index);  

    int find(const int num); 
};
