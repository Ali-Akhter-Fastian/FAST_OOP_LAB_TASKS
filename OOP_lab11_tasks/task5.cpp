//TASK 05 BY ALI AKHTER 24K-0809
#include <iostream>
#include<stdexcept>
#include<fstream>
#include<string>
using namespace std;
template <typename T>
T findMaX(T* arr, int size)
{
    T max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
   int intArr[] = { 10, 20, 5, 25, 30 };
    string strArr[] = { "Apple", "Mango", "Banana", "Peach" };
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    int strSize = sizeof(strArr) / sizeof(strArr[0]);
    cout << "Max in int array: " << findMaX(intArr, intSize) << endl;
    cout<<"Max in string array: " << findMaX(strArr, strSize) << endl;
    return 0;
}