//TASK 06 BY ALI AKHTER 24K-0809
#include <iostream>
#include<stdexcept>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    int salary, age, height;
    try
    {
        cout << endl
        << "Enter your age: ";
        cin >> age;
        if (age <= 0 || age >= 120)
        {
            throw("InvalidAgeException: Age must be between 1 and 119.");
        }
    }
    catch (const char *msg)
    {
        cout << endl
        << msg << endl;
    }
    try
    {
        cout << endl
             << "Enter your salary: ";
        cin >> salary;
        if (salary < 0)
        {
            throw("InvalidSalaryException: Salary must be positive.");
        }
    }
    catch (const char *msg)
    {
        cout << endl
             << msg << endl;
    }
    try
    {
        cout << endl
             << "Enter your height: ";
        cin >> height;
        if (height <= 0)
        {
            throw("InvalidHeightException: Height must be positive.");
        }
    }
    catch (const char *msg)
    {
        cout << endl
             << msg << endl;
    }
    return 0;
}