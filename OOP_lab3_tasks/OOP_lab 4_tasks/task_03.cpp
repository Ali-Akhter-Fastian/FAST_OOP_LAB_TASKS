// TASK # 03 by Ali Akhter 24k-0809
#include <iostream> 
using namespace std; 
typedef struct Doctor 
{ 
    string name; 
    string department; 
} Doctor; 
void GetDoctorDetails(Doctor &d) 
{ 
    cout << endl 
         << "Enter details for doctor : "; 
    cout << endl 
         << "Name : "; 
    cin >> d.name; 
    cout << endl 
         << "Department : "; 
    cin >> d.department; 
} 
class Patient 
{ 
    int ID; 
    string name; 
    int Age; 
    string Disease; 
    Doctor DoctorAssigned; 
 
public: 
    Patient() {} 
    Patient(string name, int age, string disease) 
    { 
        this->name = name; 
        this->Age = age; 
        this->Disease = disease; 
    } 
    Patient(string name, int age, string disease, Doctor &doctorAssigned) 
    { 
        this->name = name; 
        this->Age = age; 
        this->Disease = disease; 
        this->DoctorAssigned = doctorAssigned; 
    } 
    void SetID(int id) { this->ID = id; } 
    void SetDoctor(Doctor &d) { DoctorAssigned = d; } 
    int GetID(){ return ID; } 
    string GetName() { return name; } 
    int GetAge() { return Age; } 
    string GetDisease() { return Disease; } 
}; 
class Hospital 
{ 
    int NoOfPatients; 
    Patient *Patients; 
    int Count; 
 
public: 
    Hospital():NoOfPatients(0),Count(0){};
    ~Hospital() 
    { 
        if (Patients) 
            delete[] Patients; 
    } 
    void AssignDoctor(int id, Doctor &d) 
    { 
        for (int i = 0; i < NoOfPatients; i++) 
        { 
            if (Patients[i].GetID() == id) 
            { 
                Patients[i].SetDoctor(d); 
                cout << endl 
                     << "Doctor successfullly assigned !"; 
                return; 
            } 
        } 
        cout << endl 
             << "Patient not found !"; 
    } 
    void AddPatient(Patient p) 
    { 
        p.SetID(Count + 1); 
        Count++; 
        Patient *temp = new Patient[NoOfPatients + 1]; 
        for (int i = 0; i < NoOfPatients; i++) 
            temp[i] = Patients[i]; 
        temp[NoOfPatients] = p; 
        delete[] Patients; 
        Patients = temp; 
        NoOfPatients++; 
        cout << endl ;
        cout << "Patient successfully added!"; 
    } 
    void RemovePatient(int id) 
    { 
        for (int i = 0; i < NoOfPatients; i++) 
        { 
            if (Patients[i].GetID() == id) 
            { 
                Patient *temp = new Patient[NoOfPatients - 1]; 
                for (int j = 0; j < NoOfPatients; j++) 
                { 
                    if (j < i) 
                        temp[j] = Patients[j]; 
                    if (j > i) 
                        temp[j - 1] = Patients[j]; 
                } 
                delete[] Patients; 
                Patients = temp; 
                NoOfPatients--; 
                cout << endl 
                     << "Patient successfully removed!"; 
                return; 
            } 
        } 
        cout << endl 
             << "Patient not found!"; 
    } 
    void DisplayPatients() 
    { 
        cout << endl 
             << "List of patients: "; 
        for (int i = 0; i < NoOfPatients; i++) 
        { 
            cout << endl 
                 << "Id : " << Patients[i].GetID() << ", Name : " <<Patients[i].GetName() << ", Age : " << Patients[i].GetAge(); 
        } 
    } 
    void FindPatient(int id) 
    { 
        for (int i = 0; i < NoOfPatients; i++) 
        { 
            if (Patients[i].GetID() == id) 
            { 
                cout << endl 
                     << "Id : " << Patients[i].GetID() << ", Name : " <<Patients[i].GetName() << ", Age : " << Patients[i].GetAge(); 
                return; 
            } 
        } 
        cout << endl 
             << "Patient not found!"; 
    } 
}; 
int main() 
{ 
    Doctor d1,d2; 
    GetDoctorDetails(d1); 
    GetDoctorDetails(d2); 
    Patient *Patients = new Patient[2]; 
    cout << endl;
    cout<< "Enter details of patient 1 : "; 
    string Name, Disease; 
    int Age; 
    cout << endl;
    cout     << "Name: "; 
    cin >> Name; 
    cout << endl; 
    cout     << "Age: "; 
    cin >> Age; 
    cout << endl ;
     cout    << "Disease: "; 
    cin >> Disease; 
    Patients[0] = Patient(Name, Age, Disease); 
    cout << endl ;
    cout     << "Enter details for patient 2: "; 
    cout << endl ;
     cout    << "Name: "; 
    cin >> Name; 
    cout << endl ;
    cout     << "Age: "; 
    cin >> Age; 
    cout << endl ;
     cout    << "Disease: "; 
    cin >> Disease; 
    Patients[1] = Patient(Name, Age, Disease, d1); 
    Hospital h1; 
    h1.AddPatient(Patients[0]); 
    h1.AddPatient(Patients[1]); 
    h1.DisplayPatients(); 
    h1.AssignDoctor(1, d2); 
    h1.DisplayPatients(); 
    h1.RemovePatient(1); 
    h1.DisplayPatients(); 
    h1.AddPatient(Patients[0]); 
    h1.DisplayPatients(); 
    h1.FindPatient(3); 
    return 0; 
} 