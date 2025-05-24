//TASK # 04 BY ALI AKHTER 24k-0809
#include <iostream>
using namespace std;
class PaymentMethod
{
public:
    virtual bool processPayment(double amount) = 0;
};
class CreditCard : public PaymentMethod
{   
    string cardNumber;

public:
    CreditCard(string cd)
    {
        this->cardNumber = cd;
    }
    bool processPayment(double amount)
    {
        if (cardNumber.length() >= 9 && amount > 0)
        {
            cout << "CreditCard's Payment of RS:" << amount << " processed successfully"<<endl;
            return true;
        }
        else
        {
            cout << "CreditCard's Payment failed: Invalid cardnumber or transaction amount."<<endl;
            return false;
        }
    }
};
class DigitalWallet : public PaymentMethod
{
    double balance;
public:
    DigitalWallet(double b)
    {
        this->balance = b;
    }
    bool processPayment(double amount)
    {
        if (balance >= amount)
        {
            cout << "Digital Wallet Transaction successful!!" << endl;
            balance-=amount;
            return true;
        }
        else
        {
            cout << "Not Enough money, transcation failed!!!" << endl;
            return false;
        }
    }
};
int main()
{
    CreditCard c1("42401-2168889");
    DigitalWallet d1(150000);
    c1.processPayment(10000);
    d1.processPayment(5000);
    cout<<endl<<endl;
    CreditCard c2("42401-221983");
    DigitalWallet d2(20000);
    c2.processPayment(10000);
    d2.processPayment(50000);
    return 0;
}