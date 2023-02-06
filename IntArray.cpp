#include <iostream>
#include "IntArray.h"
#include "ExtExceptions.h"

using namespace std;

IntArray::IntArray(int array_size) {
    try {
        if (array_size < 0)
            throw bad_length();
    }
    catch (bad_length& e) {
        cout << "Caught " << e.what() << endl;
        cout << "Attention array dons`t create" << endl;
    }
    size = array_size;
    ptr = new int[size];
    for (int i = 0; i < size; i++) {
        ptr[i] = 0;
    }
}

IntArray::IntArray(const IntArray& other) : size(other.size) {
    ptr = new int[size];
    for (int i = 0; i < size; i++) {
        ptr[i] = other.ptr[i];
    }
}

IntArray::~IntArray()
{
    delete[] ptr;
}

const IntArray& IntArray::operator=(const IntArray& right) {
    if (&right != this) {
        if (size != right.size) {
            delete[] ptr;
            size = right.size;
            ptr = new int[size];
        }
        for (int i = 0; i < size; i++) {
            ptr[i] = right.ptr[i];
        }
    }
    return *this;
}

bool IntArray::operator==(const IntArray& right) const {
    if (size != right.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (ptr[i] != right.ptr[i]) {
            return false;
        }
    }
    return true;
}

bool IntArray::operator!=(const IntArray& right) const {
    return !(*this == right);
}

int& IntArray::operator[](int index) {
    if (index < 0 || index >= size) {
        std::cout << " Error: Subscript " << index << " out of range " << std::endl;
        exit(1);
    }
    return ptr[index];
}

const int& IntArray::operator[](int index) const {
    if (index < 0 || index >= size) {
        std::cout << " Error: Subscript " << index << " out of range " << std::endl;
        exit(1);
    }
    return ptr[index];
}

int IntArray::get_size() const
{
    return size;
}

void IntArray::erase(){
    delete[] ptr;
    ptr = nullptr;
    size = 0;
    cout << "Array cleared" << endl;
}

void IntArray::resize(int newLength){
    if (newLength == size)
        return;

    if (newLength <= 0){
        erase();
        return;
    }

    int* data{ 
        new int[newLength] 
    };

    if (size > 0){
        int elementsToCopy{ (newLength > size) ? size : newLength };

        for (int i = 0; i < elementsToCopy; ++i)
            data[i] = ptr[i];
    }

    delete[] ptr;
    ptr = data;
    size = newLength;
    cout << "Container size changed to " << newLength << endl;
}

void IntArray::insert(int value, int index){
    try {
        if (index < 0 || index > size)
            throw bad_range();
        int* bufer = new int[size + 1];
        for (int i = 0; i < index; ++i)
            bufer[i] = ptr[i];
        bufer[index] = value;

        for (int i = index; i < size; ++i)
            bufer[i + 1] = ptr[i];

        delete[] ptr;
        ptr = bufer;
        ++size;
        cout << "Insert number " << value << " before element with index " << index << endl;
    }
    catch (bad_range& e) {
        cout << "Caught " << e.what() << endl;
    }
}

void IntArray::remove(int index){
    try {
        if (index < 0 || index > size)
            throw bad_range();
        int* bufer = new int[size - 1];
        for (int i = 0; i < index; ++i){
            bufer[i] = ptr[i];
        }
        for (int i = (index + 1); i < size; ++i){
            bufer[i - 1] = ptr[i];
        }
        if (size == 1) {
            erase();
            return;
        }
        delete[] ptr;
        ptr = bufer;
        --size;
        cout << "Removing element with index " << index << endl;
    }
    catch (bad_range& e) {
        cout << "Caught " << e.what() << endl;
    }
}

void IntArray::push_front(int value) {
    insert(value, 0);
}
void IntArray::push_back(int value) {
    insert(value, size);
}

int IntArray::get_value(const int index){
    try {
        if (index < 0 || index > size)
            throw bad_length();
    }
    catch (bad_length& e) {
        cout << "Caught " << e.what() << endl;
    }
    return ptr[index];
}

int IntArray::find(const int num){
    for (int i{ 0 }; i < size; i++){
        if (num == ptr[i]) return i;
    }
    return -1;
}