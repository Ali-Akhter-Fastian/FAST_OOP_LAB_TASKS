// TASK # 04 by Ali Akhter 24k-0809
#include <iostream> 
using namespace std; 
class Employee; 
class Admin 
{ 
    int ID; 
    string name; 
 
public: 
    Admin(int ID, string name) 
    { 
        this->name = name; 
        this->ID = ID; 
    } 
    void RecordAttendance(Employee &); 
    void CalculateSalary(Employee &); 
    void SetHourlyRate(Employee &, double); 
    void Display(Employee *, int); 
}; 
class Employee 
{ 
    int ID; 
    string name; 
    string designation; 
    double hoursWorked = 0; 
    double hourlyRate = 0; 
    double salary = 0; 
 
public: 
    Employee() {} 
    Employee(int ID, string name, string designation) 
    { 
        this->ID = ID; 
        this->name = name; 
        this->designation = designation; 
    } 
    double get_hours() { return hoursWorked; } 
    void ViewSalary() 
    { 
        cout << endl 
             << "Your salary is : " << salary; 
    } 
    int GetID() { 
        return ID; 
    } 
    string GetName() { 
        return name; 
    } 
    friend void Admin ::RecordAttendance(Employee &); 
    friend void Admin ::CalculateSalary(Employee &); 
    friend void Admin ::SetHourlyRate(Employee &, double); 
}; 
void Admin ::RecordAttendance(Employee &e) 
{ 
    e.hoursWorked++; 
} 
void Admin ::CalculateSalary(Employee &e) 
{ 
    e.salary = e.hoursWorked * e.hourlyRate; 
} 
void Admin ::SetHourlyRate(Employee &e, double rate) 
{ 
    e.hourlyRate = rate; 
} 
void Admin ::Display(Employee *e, int count) 
{ 
    for (int i = 0; i < count; i++) 
    { 
        cout << endl 
             << "Details for Employee " << i + 1; 
        cout << endl 
             << "Id : " << e[i].GetID() << endl 
             << "Name : " << e[i].GetID() ;
    } 
} 
int main() 
{ 
    Employee *e = new Employee[3]; 
    e[0] = Employee(1, "Umer", "Driver"); 
    e[1] = Employee(2, "Rehan", "Passenger"); 
    e[2] = Employee(3, "Ali", "Imposter"); 
    Admin a(10, "Abdullah"); 
    a.Display(e, 3); 
    a.SetHourlyRate(e[0], 50); 
    a.SetHourlyRate(e[1], 60); 
    a.SetHourlyRate(e[2], 70); 
    a.RecordAttendance(e[0]); 
    a.RecordAttendance(e[1]); 
    a.RecordAttendance(e[1]); 
    a.RecordAttendance(e[1]); 
    a.RecordAttendance(e[2]); 
    a.RecordAttendance(e[2]); 
    a.RecordAttendance(e[2]); 
    a.RecordAttendance(e[1]); 
    a.RecordAttendance(e[0]); 
    a.RecordAttendance(e[0]); 
    a.RecordAttendance(e[0]); 
    a.CalculateSalary(e[0]); 
    a.CalculateSalary(e[1]); 
    a.CalculateSalary(e[2]); 
    e[0].ViewSalary(); 
    e[1].ViewSalary(); 
    e[2].ViewSalary(); 
    return 0; 
} 