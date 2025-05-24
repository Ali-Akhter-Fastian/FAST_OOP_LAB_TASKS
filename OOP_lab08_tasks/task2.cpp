//TASK 02 BY ALI AKHTER 24K-0809
#include <iostream>
using namespace std;
class Account{
   string accNumber;
    string accHolder;
    double balance;
public:
    Account(){}
    void setBalance(double balance){
        this->balance = balance;}
    Account(string accHolder, string accNumber, double balance){
        this->accHolder = accHolder;
        this->accNumber = accNumber;
        this->balance = balance;}
    Account operator+(const Account &other){
        Account A;
        A.balance = this->balance + other.balance;
        return A;}
    Account operator-=(double amount){
        this->balance -= amount;
        return *this;
    }
    bool operator>(const Account &other){
        return this->balance > other.balance;
    }
    string getAccHolder(){return accHolder;}
    double getBalance(){return balance;}
    friend ostream &operator<<(ostream &output, const Account &account);
};
ostream &operator<<(ostream &output, const Account &account){
    output <<"Name: "<< account.accHolder<<endl;
    output <<"Account Number: "<< account.accNumber<<endl;
    output <<"Balance: "<< account.balance<<endl;
    return output;}
int main(){
    Account a1("Gllen Philips","08891",30000);
    Account a2("Viv Richards","02241",40000);
    Account a3 = a1 + a2;
    cout << "The total balance of Account no 1 and Account no 2 is= "<<a3.getBalance()<<endl;
    a2 -= 2000;
    a1.setBalance(a1.getBalance()+2000);
    cout<<"~~~~After the Transfer~~~~"<<endl;
    cout<<"Account 1's balance= "<<a1.getBalance()<<endl;
    cout<<"Account 2's balance= "<<a2.getBalance()<<endl<<endl;
    if (a1>a2)  cout<<"Account no 1 balance is lesser than Account 2"<<endl;
    else    cout<<"Account no 2 balance is lesser than Account 1"<< endl;
    cout<<a1<<endl;
    cout<<a2<<endl;
    return 0;
}