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

    cout << "Value of container element with index 5 = " << array1.get_value(5) << endl; //����� � ������ �������� �� �������
    cout << "Container index with value 3 = " << array1.find(3) << endl; // ����� � ������� �������� 3 � ������� ������ ������
    array1.resize(10); //�������� ������ ������� �� 10 ���������

    cout << "Display array" << endl;
    for (int i = 0; i < array1.get_size(); i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    array1.insert(33, 6); //�������� ����� 33 ����� ��������� � �������� 6
    array1.remove(3); // ������� ������� 3
    array1.push_front(22); //�������� 22 � ������
    array1.push_back(44); //�������� 44 � �����

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