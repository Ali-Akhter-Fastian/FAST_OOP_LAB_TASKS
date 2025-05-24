#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
int main(){
    ifstream f("story.txt",ios::in);
    string line;
    string word;
    int a;
    while(getline(f,line)){
        istringstream ss(line);
        while(ss>>a){
          
        
            cout<<"Integer: "<<a<<endl;
        }
    }
    return 0;
}