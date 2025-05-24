//TASK # 03 by ALI AKHTER 24k-0809
#include<iostream>
using namespace std;
void findPrimesInRange(int a, int b){
    int count=0;
    cout<<"Prime numbers between "<<a<<" and "<<b<<" are: "<<endl;
    for(int i=a;i<b;i++){
        for(int j=2;j<i/2;j++){
            if(i%j==0){
                count++;  
                break;
            } 
        }
        if(count==0)    cout<<i<<" ";
        count=0;
    }
}
int main(){
    int a,b;
    cout<<"Start number: ";
    cin>>a;
    cout<<"End number: ";
    cin>>b;
    findPrimesInRange(a,b);
    return 0;
}