//TASK # 01 by ALI AKHTER 24k-0809
#include<iostream>
using namespace std;
void Swapvalues(int *a, int *b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;    
}
int main(){
   int a,b;
   cout<<"Enter 1st value: ";
   cin>>a;
   cout<<"Enter 2nd value: ";
   cin>>b;
   cout<<"The initital values are a="<<a<<" b="<<b<<endl;
   Swapvalues(&a,&b); //calling function to swap values using pointers//
   cout<<"Values after swappping a="<<a<<" b="<<b<<endl;
   return 0;
}