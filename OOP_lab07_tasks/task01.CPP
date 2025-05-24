//#TASK 01 by Ali Akhter 24k-0809
#include<iostream>
using namespace std;
class Device{
    private:
    string devideID;
    string status;
    public:
    Device(){};
    Device(string deviceID, string status){
        this->devideID=deviceID;
        this->status=status;
    }
    virtual void turnON(){
        status = "ON";
    }
    virtual void turnOFF(){
        status = "OFF";
    }
    void Setstatus(string status){
        this->status=status;
    }
    string getstatus(){return status;};
};
class Light : public Device{
    private:
    int brightness;
    public:
    Light(){};
    Light(string ID, string status,int brightness):Device(ID,status){
        this->brightness=brightness;
    }
    void dim(int level){
        if(level<brightness){
        brightness-=level;
        cout<<"Brightness Updated!!!"<<endl;
        }
        else   cout<<"The light level is already very low!!!"<<endl;
    }
     void turnON(){
       Setstatus("ON");
       cout<<"Light ON"<<endl;
    }
    void turnOFF(){
       Setstatus("OFF");
       cout<<"Loght OFF"<<endl;
    }
};
class Camera : public Device{
    private:
    bool IsRecording;
    public:
    Camera(){};
    Camera(string ID, string status, bool recording):Device(ID,status){
        this->IsRecording=recording;
    }
    void startRecording(){
        if(IsRecording) cout<<"The camera is already recording!!!"<<endl;
        else{
            IsRecording=true;
            cout<<"Camera is now on recording mode!!!"<<endl;
        }
    }
      void turnON(){
       Setstatus("ON");
       cout<<"Camera ON"<<endl;
    }
    void turnOFF(){
       Setstatus("OFF");
       cout<<"Camera OFF"<<endl;
    }
};
class Thermostat : public Device{
    private:
    int temperature;
    public:
    Thermostat(){};
    Thermostat(string ID, string status,int temp):Device(ID,status){
        this->temperature=temp;
    }
    void setTemperature(int temp){
        temperature=temp;
        cout<<"Temperature setted!!!"<<endl;
    }
      void turnON(){
       Setstatus("ON");
       cout<<"Thermostat ON"<<endl;
    }
    void turnOFF(){
       Setstatus("OFF");
       cout<<"Thermostat OFF"<<endl;
    }
};
class Routine{
    private:
    Device *devices;
    int devicecount;
    string RoutineID;
    string name;
    public:
    Routine(){};
    Routine(string ID, string name):devices(nullptr),devicecount(0){
        this->RoutineID=ID;
        this->name=name;
    }
    void addDevice(Device &device){
        Device *temp=new Device[devicecount+1];
        for(int i=0;i<devicecount;i++){
        temp[i]=devices[i];
        }
        temp[devicecount]=device;
        if(devices!=nullptr)
        delete[] devices;
        devices=temp;
        devicecount++;
        cout<<"Device Added Successfully!!!"<<endl;
    }
    void addDevice(Device *device, int numdevice){
        int j=0;
        Device *temp=new Device[devicecount+numdevice];
        for(int i=0;i<devicecount;i++)
        temp[i]=devices[i];
        for(int i=devicecount;i<numdevice;i++){
        temp[i]=device[j];
        j++;
        }
         if(devices!=nullptr)
        delete[] devices;
        devices = temp;
        devicecount+=numdevice;
        cout<<"Devices Added Successfully!!!"<<endl;
    }
    void execute(){
        for(int i=0;i<devicecount;i++){
            devices[i].turnON();
            cout<<"Device "<<i+1<<" turned on"<<endl;
        }
        cout<<"Routine "<<name<<" executed"<<endl;
    }
};
class HomeOwner{
    private:
    Routine *routines;
    int routinecount;
    string HomeOwnerID;
    string name;
    public:
    HomeOwner(){};
    HomeOwner(string ID , string name){
        routines=nullptr;
        routinecount=0;
        this->name=name;
        this->HomeOwnerID=ID;
    }
    void createRoutine(Routine &routine){
        Routine *temp=new Routine[routinecount+1];
        for(int i=0;i<routinecount;i++){
        temp[i]=routines[i];
        }
        temp[routinecount]=routine;
         if(routines!=nullptr)
        delete routines;
        routines=temp;
        routinecount++;
        cout<<"Routine Added Successfully!!!"<<endl;
    }
    void controlDevice(Device device){
        string choice;
        while(1){
        cout<<"What do you want to do with that device(Enter 'ON','OFF','Getstatus' or 'exit'): ";
        cin>>choice;
        if(choice=="ON"){
            device.turnON();
            cout<<"turned on"<<endl;
        }
        else if(choice=="OFF"){
            device.turnOFF();
            cout<<"turned off"<<endl;
        }
        else if(choice=="Getstatus"){
            string status= device.getstatus();
            cout<<"Status: "<<status<<endl;
        }
        else if(choice == "Exit" || "exit") break;
        else cout<<"Invalid Input!!!"<<endl;
    }

    }
};


int main(){
Light l1("L1","OFF",80);
Camera c1("C1","OFf",false);
Thermostat t1("T1","OFF",24);
l1.turnON();
l1.dim(40);
c1.startRecording();
t1.setTemperature(22);
Routine r1("101","Morning Mode");
r1.addDevice(l1);
r1.addDevice(c1);
r1.addDevice(t1);
r1.execute();
HomeOwner h1("100","Ali");
h1.createRoutine(r1);
h1.controlDevice(l1);
}
