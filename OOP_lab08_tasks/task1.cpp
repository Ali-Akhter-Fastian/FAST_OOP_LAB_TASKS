//TASK 01 BY ALI AKHTER 24K-0809
#include <iostream>
using namespace std;
class Device
{
private:
    string id;
    string type;
protected:
    double powerRating;
    bool status;
public:
    Device() {}
    Device(string id, string type, double power, bool status) : id(id), type(type), powerRating(power), status(status) {}
    string getType() { return type; }
    virtual void turnOn(){
        cout << endl
             << type << " ID : " << id << "  turned ON";
        status = true;
    }
    void turnOff(){
        status = false;
    }
    virtual double calculatePowerUsage(int) = 0;
};
class Light : public Device
{
public:
    Light() {}
    Light(string id,string light, double power) : Device(id, light , power, false){}
    double calculatePowerUsage(int hours){
        double powerConsumption = powerRating * hours;
        return powerConsumption;
    }
};
class Fan : public Device
{
    int speedFactor;
public:
    Fan() {}
    Fan(string id, string fan, double power) : Device(id, fan , power, false) {}
    Fan(string id, string fan, double power, int speedFactor) : Device(id, fan , power, false), speedFactor(speedFactor) {}
    void setSpeed(int speed){speedFactor = speed; }
    void turnOn(){
        Device ::turnOn();
        cout << " at speed " << speedFactor;
    }
    double calculatePowerUsage(int hours){
        double powerConsumption = powerRating * hours * speedFactor;
        return powerConsumption;
    }
};
class AirConditioner : public Device{
    double currentTemp;
    double desiredTemp;
public:
    AirConditioner() {}
    AirConditioner(string id, string Air ,double power) : Device(id,Air, power, false) {}
    AirConditioner(string id,string Air, double power, int currentTemp) : Device(id, Air , power, false), currentTemp(currentTemp) {}
    void setCurrentTemp(int temp) { currentTemp = temp; }
    void setDesiredTemp(int temp) { desiredTemp = temp; }
    void turnOn(int desiredTemp){
        status = true;
        if (desiredTemp)
            setDesiredTemp(desiredTemp);
        Device::turnOn();
        cout << " Cooling to " << desiredTemp << "'C";}
    double calculatePowerUsage(int hours){
        double powerConsumption = (powerRating * hours * (1 - (currentTemp - desiredTemp) / 100));
        return powerConsumption;
}
};
class User{
    string id;
    string role;
    int accessLevel;
    bool isAccessible(Device *d){
        if (role == "MaintenanceStaff")
            return true;
        if (role == "RegularUser"){
            if (d->getType() == "SecuritySystem")
            return false;
            else
            return true;}
        cout << endl<< "Ivalid Role !!";
        return false;}
public:
    User() {}
    User(string id, string role, int accessLevel) : id(id), role(role), accessLevel(accessLevel) {}
    void viewAccessibleDevices(Device *devices[], int count);
    void accessSecurityLogs(Device *d);
};
class SecuritySystem : public Device{
    string *securityLogs;
    int logsCount;
    bool logSecurityStatus;
public:
    SecuritySystem():securityLogs(NULL) {
        this->logSecurityStatus=true;
    }
    SecuritySystem(string id,string name, double power) : Device(id,name, power, false) {
        this->securityLogs=NULL;
        this->logsCount=0;
        this->logSecurityStatus=true;
    }
    double calculatePowerUsage(int hours){
        return powerRating * hours;
    }
    void addLog(string time){
        string log = "Intrusion detected at time " + time;
        string *temp = new string[logsCount + 1];
        for (int i = 0; i < logsCount; i++)
            temp[i] = securityLogs[i];
        temp[logsCount++] = log;
        delete[] securityLogs;
        securityLogs = temp;
        logSecurityStatus = false;}
    int getLogsCount()const{ return logsCount; }
    friend void User ::accessSecurityLogs(Device *d);
    friend class MaintenanceTool;
};
void User ::viewAccessibleDevices(Device *devices[], int count)
{
    cout << endl<< "User " << id << " accessible devices : ";
    for (int i = 0; i < count; i++)
    {
        if (isAccessible(devices[i]))
            cout << endl <<"* "<< devices[i]->getType();
        else
        {
            SecuritySystem *s = (SecuritySystem *)devices[i];
            s->addLog("1:00 PM");
        }
    }
}
void User ::accessSecurityLogs(Device *d){
    if (!isAccessible(d)){
        cout << endl<< "User " << id << " Access denied !!";
        return;
    }
    cout<<endl<<"User "<<id<<" Security Logs Accessed: ";
    SecuritySystem *s = (SecuritySystem *)d;
    for (int i = 0; i < s->logsCount; i++)cout<<endl<<"- "<< s->securityLogs[i];
    if (s->logSecurityStatus == false) cout<<endl<<"- System Reset Required!";
}
class MaintenanceTool
{
public:
    void resetSecurityAlerts(SecuritySystem &s){
        delete[] s.securityLogs;
        s.securityLogs = NULL;
        s.logsCount = 0;
        s.logSecurityStatus = true;
        cout << endl
             << "- Security alerts reset!";}
};
int main()
{User user1("U001", "Regular User", 1);
    User user2("U002", "Maintenance Staff", 2);

    Light light1("L001", "LED Light", 10);
Fan fan1("F001", "Ceiling Fan", 75, 3);
AirConditioner ac1("AC001", "Split AC", 1500, 25);
SecuritySystem secSys1("S001", "Home Alarm", 100);


    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn(10);
    secSys1.turnOn();
    cout << light1.calculatePowerUsage(5) << endl; // 50 Watts
    cout << fan1.calculatePowerUsage(3) << endl; // Based on speed factor
    cout << ac1.calculatePowerUsage(6) << endl; // Adjusted for temp
    cout << secSys1.calculatePowerUsage(24) << endl; // Fixed consumption
    Device *devices[4] = {
        &light1, 
        &fan1,
         &ac1,
        &secSys1
    };
    user1.viewAccessibleDevices(devices, 4); // Can see lights, fans, ACs, but NOT security systems
    user2.accessSecurityLogs(devices[2]); // Allowed to view security logs
    return 0;
}