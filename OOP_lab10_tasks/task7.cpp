#include<iostream>
#include<fstream>
using namespace std;
struct Student{
    char name[50];
    int id;
    float GPA; 
}student;
void write(){
    ofstream f;
    f.open("student.dat",ios::app | ios::binary);
    cout<<"NAME: ";
    cin.getline(student.name,50);
    cout<<"ID: ";
    cin>>student.id;
    cout<<"GPA: ";
    cin>>student.GPA;
    cin.ignore();
    f.write(reinterpret_cast<char*>(&student),sizeof(student));
    cout<<"DATA WRITTEN\n";
    f.close();
}
void read(){
    ifstream f;
    f.open("student.dat",ios::in | ios::binary);
    cout<<"\nNAME\tID\tGPA\n";
    while(f.read(reinterpret_cast<char*>(&student),sizeof(student))){
        cout<<student.name<<"\t"<<student.id<<"\t"<<student.GPA<<"\n";
    }
    
}
int main(){
 char check='y';
 while(check!='n'){
     write();
     cout<<"Press 'y' to continue inputting or 'n' to exit and 'r' to show data: ";
     cin>>check;
     if(check=='r'){
        read();
        return 0;
     }
 }
}