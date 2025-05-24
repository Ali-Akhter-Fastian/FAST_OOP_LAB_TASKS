//TASK 01 BY ALI AKHTER 24K-0809
#include <iostream>
#include<stdexcept>
#include<fstream>
#include<string>
using namespace std;
template <typename T>
void swapValues(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 5, b = 10;
    cout << "Before swap: a = " << a << ", b = " << b << endl;  //before swap
    swapValues(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;   //After swap
    double x = 1.5, y = 2.5;
    cout << "Before swap: x = " << x << ", y = " << y << endl;  //before swap
    swapValues(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;   //After swap
    char c1 = 'A', c2 = 'B';
    cout << "Before swap: c1 = " << c1 << ", c2 = " << c2 << endl;  //before swap
    swapValues(c1, c2);
    cout << "After swap: c1 = " << c1 << ", c2 = " << c2 << endl;   //After swap
    return 0;
}