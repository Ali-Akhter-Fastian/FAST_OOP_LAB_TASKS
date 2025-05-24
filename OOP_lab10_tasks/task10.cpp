//TASK 10 BY ALI AKHTER 0809
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream f("backup_log.txt", ios::app);
    char logMessage[50];
    char check;
    do
    {
        cout<<"Enter the log message: ";
        cin.getline(logMessage, 50);

        f<<logMessage<<endl;
        cout<<"The current file size is: "<<f.tellp();

        cout<<"\nDo you want to enter another message(Y/N): ";
        cin>>check;
        cin.ignore();
    } while (check!='N');
    return 0;
}

