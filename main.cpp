#include <iostream>
#include "IntArray.h"

using namespace std;

int main() {

    static IntArray array1;
    static IntArray array2;
    static int array_size = 20;
    array1 = { array_size };
    cout << "Array created" << endl;

    for (int i = 0; i <20; ++i) {
        array1[i] = i+1;
    }

    cout << "Display array" << endl;
    for (int i = 0; i < array1.get_size(); i++) {
        cout << array1[i] << " ";
    }

    cout << endl;
    cout << "Copying an array" << endl;
    array2 = array1;

    cout << "Display arrays" << endl;
    for (int i = 0; i < array1.get_size(); i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    if (array2.get_size() > 0) {
        for (int i = 0; i < array2.get_size(); i++) {
            cout << array2[i] << " ";
        }
        cout << endl;
    }

    cout << "Value of container element with index 5 = " << array1.get_value(5) << endl; //найти в масиве значение по индексу
    cout << "Container index with value 3 = " << array1.find(3) << endl; // найти в массиве значение 3 и вывести индекс €чейки
    array1.resize(10); //изменить размер массива до 10 элементов

    cout << "Display array" << endl;
    for (int i = 0; i < array1.get_size(); i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    array1.insert(33, 6); //вставьте число 33 перед элементом с индексом 6
    array1.remove(3); // удалить элемент 3
    array1.push_front(22); //добавить 22 к началу
    array1.push_back(44); //добавить 44 в конец

    cout << "Display arrays " << endl;
    for (int i = 0; i < array1.get_size(); i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    if (array2.get_size() > 0) {
        for (int i = 0; i < array2.get_size(); i++) {
            cout << array2[i] << " ";
        }
        cout << endl;
    } 
    return 0;
}