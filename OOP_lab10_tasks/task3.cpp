//TASK 03 BY ALI AKHTER 24K-0809
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string name;  
    string email;
    string check="Yes";
    ofstream f;
    f.open("signup.txt",ios::app);
    while(check!="exit"){
        cout<<"Enter name: ";
        getline(cin,name);
        cout<<"Enter email: ";
        getline(cin,email);
        f<<"Name: "<<name<<endl<<"E-mail: "<<email<<endl;
        cout<<"Enter 'exit' if you don't want to continue entering else press 'Y': ";
        cin>>check;
        cin.ignore();
    }  
    f.close();
}