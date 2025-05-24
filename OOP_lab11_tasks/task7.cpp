//TASK 07 BY ALI AKHTER 24K-0809
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class SmartArray {
    T* arr;
    int size;

public:
    SmartArray(int s) : size(s) {
        arr = new T[size];
        cout << endl << "Enter elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

    ~SmartArray() {
        delete[] arr;
    }
};

int main() {
    int s;
    cout << "Array size: ";
    cin >> s;

    SmartArray<int> intArray(s);

    try {
        cout << endl << "Accessing index 2: ";
        cout << intArray[2] << endl;

        cout << "Accessing index 5: "; 
        cout << intArray[5] << endl;   
    }
    catch (const out_of_range& e) {
        cerr << "\nCaught exception in main: " << e.what() << endl;
    }
    catch (...) {
        cerr << "\nCaught unknown exception in main" << endl;
    }

    return 0;
}
