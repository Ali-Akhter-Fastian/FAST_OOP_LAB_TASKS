//TASK # 07 by ALI AKHTER 24k-0809
#include <string>
#include <iostream>
using namespace std;
struct Student {
string name;
int id;
int mark[3];
};
void inputStudent(Student* ptr); // function prototype for getting input
void displayStudent(Student* ptr); // function prototype for displaying details
int main () {
Student stu; // declaring a Student object
Student* stuPtr = &stu; // defining a pointer for the object
inputStudent(stuPtr); // calling function to get input into the object
displayStudent(stuPtr); // calling function to print the details of the object
return 0;
} // end main
void inputStudent(Student* ptr){
    cout<<"Enter Student's name: ";
    getline(cin,ptr->name);
    cout<<"Enter Student's ID: ";
    cin>>ptr->id;
    cout<<"  ~~Enter marks for 3 subjects~~  "<<endl;
    for(int i=0;i<3;i++){
        cout<<"Subject "<<i+1<<": ";
        cin>>ptr->mark[i];
    }
}
void displayStudent(Student* ptr){
    cout<<endl<<endl<<"    ~~Details of Student are as follows~~"<<endl;;
    cout<<"->Name= "<<ptr->name<<endl;
    cout<<"->ID= "<<ptr->id<<endl;
    cout<<"   ~~Marks~~"<<endl;
    for(int i=0;i<3;i++){
        cout<<"->Subject "<<i+1<<"= "<<ptr->mark[i]<<endl;
    }
}