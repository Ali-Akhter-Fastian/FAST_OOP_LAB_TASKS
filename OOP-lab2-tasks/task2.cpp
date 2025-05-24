//TASK # 02 by ALI AKHTER 24k-0809
#include<iostream>
#include<string>
using namespace std;
void firstAndlast(string name,char a, int *ptr1,int *ptr2){
    int b=1;
 for(int i=0;i<name.length();i++){
     if(name[i]==a && b==1){
        *ptr1=i;
        b++;
     }
     else if(name[i]==a){
        *ptr2=i;
     }
 }
}
int main(){
    int first=-1,last=-1;
    string input;
    cout<<"Enter a string: ";
    cin>>input;
    char character;
    cout<<"Enter a character to find out: ";
    cin>>character;
    firstAndlast(input,character,&first,&last);
    cout<<"First occurance: "<<first<<endl;
    cout<<"Last occurance: "<<last<<endl;
    // cout<<input.length()<<endl;
    return 0;
}