#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream f;
    f.open("draft.txt",ios::in |ios::out);
    string word;
    string correction="the";
    while(f>>word){
        if(word=="teh"){
            int position=f.tellg();
            f.seekp(position-3,ios::beg);
            f<<correction;
            cout<<"TYPO CORRECTED!!!"<<endl;
            return 0;
        }
    }
}