//TASK # 02 BY ALI AKHTER 24k-0809
#include <iostream>
using namespace std;
class SmartDevice
{
protected:
    bool isOn;
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool getStatus() = 0;
};
class LightBulb : public SmartDevice
{
    int brightness;
public:
    LightBulb(int brightness)
    {
        this->brightness = brightness;
    }
    void turnOn()
    {
        isOn = true;
    }
    void turnOff()
    {
        isOn = false;
    }
    bool getStatus()
    {
        cout<<"Light Bulb: "<<endl;
        return isOn;
    }
};
class Thermostat : public SmartDevice
{
    double temprature;
public:
    Thermostat(double temprature)
    {
        this->temprature = temprature;
    }
    void turnOn()
    {
        isOn = true;
    }
    void turnOff()
    {
        isOn = false;
    }
    bool getStatus()
    {
        cout<<"Thermostat: "<<endl;
        return isOn;
    }
};
int main()
{
    SmartDevice *SD[2];
    SD[0] = new LightBulb(13);
    SD[1] = new Thermostat(60);
for (int i = 0; i < 2; i++)
{
    SD[i]->turnOn();
    if(SD[i]->getStatus()){cout<<"ON"<<endl;}
    else {cout<<"OFF"<<endl;}
    SD[i]->turnOff();
    if(SD[i]->getStatus()){cout<<"ON"<<endl;}
    else {cout<<"OFF"<<endl;}
}
return 0;  
}