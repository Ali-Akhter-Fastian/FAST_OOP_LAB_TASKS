#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream f("article.txt",ios::in);
    char ch;
    string line;
    string word;
    int index,start=0;
    while(getline(f,line)){
        start=0;
        while((index=line.find(',',start))!=string::npos){
            word=line.substr(start,index-start);
            cout<<word<<endl;
            start=index+1;
        }
    }

}