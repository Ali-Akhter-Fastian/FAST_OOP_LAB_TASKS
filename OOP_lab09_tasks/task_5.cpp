//TASK # 05 BY ALI AKHTER 24k-0809
#include <iostream>
using namespace std;
class Activity
{
public:
    virtual double calculateCaloriesBurned(double weight) = 0;
};
class Running : public Activity
{
    double distance;
    double  time;
public:
    Running(double d, double t){
        this->distance=d;
        this->time=t;
    }
    double calculateCaloriesBurned(double weight)
    {
        return distance * 1.03 * weight;
    }
};
class Cycling : public Activity
{
    double speed;
    double time;
public:
    Cycling(double s, double t){
        this->speed=s;
        this->time=t;
    }
    double calculateCaloriesBurned(double weight)
    {
        double distance = speed * time;
        return distance * 1.03 * weight;
    }
};
int main()
{
    double w;
    cout << "Enter your weight in kg: ";
    cin >> w;
    Running run(5, 1.5); 
    Cycling cycle(20, 1.2); 
    cout << "Calories burned running: " << run.calculateCaloriesBurned(w) << " kcal" << endl;
    cout << "Calories burned cycling: " << cycle.calculateCaloriesBurned(w) << " kcal" << endl;
    return 0;
}