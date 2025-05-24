//TASK # 01 BY ALI AKHTER 24k-0809
#include <iostream>
using namespace std;
class Vehicle
{
    string model;
    double rate;
public:
    Vehicle(string model, double rate)
    {
        this->model = model;
        this->rate = rate;
    }
    virtual void getDailyRate() = 0;
    virtual void displayDetails() = 0;
    string getModel() const { return model; }
    double getRate() const { return rate; }
    void setModel(string m){this->model=m;}
    void setRate(double r){this->rate=r;}
};
class Car : public Vehicle
{
public:
Car(string m, double r):Vehicle(m,r){}
    void getDailyRate()
    {
        cout<<"The daily rate of car is: "<<Vehicle::getRate()<<endl;
    }
    void displayDetails()
    {
        cout<<endl<<"Details Of Car are as follows: "<<endl;
        cout<<"Car's daily Rate: "<<Vehicle::getRate()<<endl;
        cout<<"Car's model: "<<Vehicle::getModel()<<endl;
    }
};
class Bike : public Vehicle
{
public:
    Bike(string m, double r) : Vehicle(m, r) {}
    void getDailyRate()
    {
        cout<<"The daily rate of Bike is: "<<Vehicle::getRate()<<endl;
    }
    void displayDetails()
    {
        cout<<endl<<"Details of Bike are as follows: "<<endl;
        cout<<"Bike's daily Rate: "<<Vehicle::getRate()<<endl;
        cout<<"Bike's model: "<<Vehicle::getModel()<<endl;
    }
};
int main()
{
    Vehicle *v[2];
   
    v[0] = new Car("SuzukiA1", 200000);
    v[1] = new Bike("AltoA2", 200000);
for (int i = 0; i < 2; i++)
{
     v[i]->getDailyRate();
    v[i]->displayDetails();
}
return 0;
}