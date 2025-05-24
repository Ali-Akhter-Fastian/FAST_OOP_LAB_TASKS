//TASK # 05 by ALI AKHTER 24k-0809
#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,m,j=0;
    cout<<"Enter the size of first string:";
    cin>>n;
    cout<<"Enter characters: ";
    char *ptr1=new char[n];
    for(int i=0;i<n;i++){
        cin>>*(ptr1+i);
    }
    cout<<"Enter the size of second string:";
    cin>>m;
    cout<<"Enter characters: ";
    char *ptr2=new char[m];
    for(int i=0;i<m;i++){
        cin>>*(ptr2+i);
    }
    char *ptr3=new char[m+n];
    for(int i=0;i<n;i++){
            *(ptr3+j)=*(ptr1+i);
            j++;
    }
    for(int i=0;i<m;i++){
            *(ptr3+j)=*(ptr2+i);
            j++;
    }
    cout<<endl;
    cout<<"The 1st string provided is: ";
    for(int i=0;i<n;i++){
        cout<<*(ptr1+i);
    }
    cout<<endl;
     cout<<"The 2nd string provided is: ";
    for(int i=0;i<m;i++){
        cout<<*(ptr2+i);
    }
    cout<<endl;
    cout<<"The Concatinated string is: ";
    for(int i=0;i<m+n;i++){
        cout<<*(ptr3+i);
    }
    delete[] ptr1;
    delete[] ptr2;
    delete[] ptr3;
    return 0;
}