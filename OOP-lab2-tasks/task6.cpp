//TASK # 06 by ALI AKHTER 24k-0809
#include<iostream>
#include<string>
using namespace std;
struct Employee
{
    int EmployeeNumber;
    string name;
    double BasicSalary;
    double HomeAllowances;
    double MedicalAllowances;
    double Tax;
    double GrossSalary;
    double NetSalary;
};
void display(struct Employee e1);
void empSalary(struct Employee *e1){
    e1->HomeAllowances=e1->BasicSalary*10/100;
    e1->MedicalAllowances=e1->BasicSalary*5/100;
    e1->Tax=e1->BasicSalary*4/100;
    e1->GrossSalary=e1->HomeAllowances+e1->MedicalAllowances+e1->BasicSalary;
    e1->NetSalary=e1->GrossSalary-e1->Tax;
}
void display(struct Employee e1){
    cout<<"Employee Number= "<<e1.EmployeeNumber<<" "<<endl;
    cout<<"Name= "<<e1.name<<" "<<endl;
    cout<<"Basic Salary= "<<e1.BasicSalary<<" "<<endl;
    cout<<"Home Allowance= "<<e1.HomeAllowances<<" "<<endl;
    cout<<"Medical Allowance= "<<e1.MedicalAllowances<<" "<<endl;
    cout<<"Tax= "<<e1.Tax<<" "<<endl;
    cout<<"Gross Salary= "<<e1.GrossSalary<<" "<<endl;
    cout<<"Net Salary= "<<e1.NetSalary<<" "<<endl;
}
int main(){
    Employee e1;
    cout<<"Enter Employee Number= ";
    cin>>e1.EmployeeNumber;
    cout<<"Enter Name= ";
    cin.ignore();
    getline(cin,e1.name);
    cout<<"Basic Salary= ";
    cin>>e1.BasicSalary;
    empSalary(&e1);
    cout<<endl<<endl;
    display(e1);
}