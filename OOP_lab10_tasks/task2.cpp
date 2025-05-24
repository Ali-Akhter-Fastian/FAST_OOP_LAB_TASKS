//Task 02 by ALI AKHTER 24k-0809
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream f;
    f.open("diary.txt",ios::app);
    string line;
    cout<<"ENTER LINE: ";
    getline(cin,line);      
    while(line!="exit"){
        f<<line<<endl;
        cout<<"ENTER LINE: ";
        getline(cin,line);
    }
    f.close();
}