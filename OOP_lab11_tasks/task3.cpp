//TASK 03 BY ALI AKHTER 24K-0809
#include <iostream>
#include<stdexcept>
#include<fstream>
#include<string>
using namespace std;
template <typename T1, typename T2>
class Pair{
    T1 first;
    T2 second;

public:
    Pair(T1 first, T2 second) : first(first), second(second) {}
    void display() const
    {
        cout << "Pair:(" << first << ", " << second <<")"<< endl;
    }
};
int main()
{
    Pair<int, string> pair1(5, "Hello");
    pair1.display();
    Pair<double, int> pair2(3.14, 42);
    pair2.display();
    return 0;
}