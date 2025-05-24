#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream f;
    f.open("secret.txt",ios::in);
    if(!f.is_open())    {
        cout<<"Can't open file\n";
        return 1;
    }
    char ch;
    int count=0;
    while(f.get(ch)){
        if(ch>='A' && ch<='Z'){
            count++;
        }
    }
    f.close();
    cout<<"UPPER CASE LETTERS: "<<count<<endl;
    return 0;
}