#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream f("article.txt",ios::in);
    f.seekg(0,ios::end);
    streampos size=f.tellg();
    cout<<size;
    f.seekg(size/2,ios::beg);
    string line;
    int linecount=0;
    while(getline(f,line) && linecount<10){
        cout<<line<<endl;
        linecount++;
    }
}