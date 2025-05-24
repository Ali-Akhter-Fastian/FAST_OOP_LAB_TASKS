//TASK 04 BY ALI AKHTER 24K-0809
#include <iostream>
#include<stdexcept>
#include<fstream>
#include<string>
using namespace std;
class Bank{
    double balance;

public:
    Bank(double initialBalance) : balance(initialBalance) {}
    void withdraw(double amount)
    {
        try
        {
            if (amount > balance)
            {
                throw runtime_error("Insufficient funds to complete withdrawl");
            }
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
        catch (const runtime_error &e)
        {
            cout << "Error: " << e.what() << endl;
        }
        catch (...)
        {
            cout << "An unexpected error occurred." << endl;
        }
    }
};
int main()
{
    Bank myBank(1000.0);
    myBank.withdraw(500.0); 
    myBank.withdraw(600.0);
    myBank.withdraw(200.0); 
    return 0;
}