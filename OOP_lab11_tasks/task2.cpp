//TASK 02 BY ALI AKHTER 24K-0809
#include <iostream>
#include<stdexcept>
#include<fstream>
#include<string>
using namespace std;
int main(){
    int n, d;
    cout << "Enter numerator: ";
    cin >> n;
    cout << "Enter denominator: ";
    cin >> d;
    try
    {
        if (d == 0)
        {
            throw runtime_error("Divison by is not allowed!");
        }
        double result = static_cast<double>(n) / d;
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Unexpected Error" << endl;
    }
    return 0;
}