//TASK # 01 by ALI AKHTER 24k-0809
//This task can be done using arrays but arrays was not included in the topics of lab 01
#include<iostream>
using namespace std;
int main(){
    int amount;
    cout<<"Enter an amount: ";
    cin>>amount;
    cout<<"Minimum notes required for RS :"<< amount <<" are"<<endl;
    int div1=amount/5000;
    if(div1>0){
        amount=amount%5000;
        if(amount>=0){
            cout<<"5000 x "<< div1 <<endl;
        }
        else{
            cout<<"5000 x 0"<<endl;
        }
    }
    else{
            cout<<"5000 x 0"<<endl;
        }
    int div2=amount/1000;
    if(div2>0){
        amount=amount%1000;
        if(amount>=0){
            cout<<"1000 x "<< div2 <<endl;
        }
        else{
            cout<<"1000 x 0"<<endl;
        }
    }
    else{
            cout<<"1000 x 0"<<endl;
        }
    int div3=amount/500;
    if(div3>0){
        amount=amount%500;
        if(amount>=0){
            cout<<"500 x "<< div3 <<endl;
        }
        else{
            cout<<"500 x 0"<<endl;
        }
    }
    else{
            cout<<"500 x 0"<<endl;
        }
     int div4=amount/100;
    if(div4>0){
        amount=amount%100;
        if(amount>=0){
            cout<<"100 x "<< div4 <<endl;
        }
        else{
            cout<<"100 x 0"<<endl;
        }
    }
    else{
            cout<<"100 x 0"<<endl;
        }
    int div5=amount/20;
    if(div5>0){
        amount=amount%20;
        if(amount>=0){
            cout<<"20 x "<< div5 <<endl;
        }
        else{
            cout<<"20 x 0"<<endl;
        }
    }
    else{
            cout<<"20 x 0"<<endl;
        }
    int div6=amount/10;
    if(div6>0){
        amount=amount%10;
        if(amount>=0){
            cout<<"10 x "<< div6 <<endl;
        }
        else{
            cout<<"10 x 0"<<endl;
        }
    }
    else{
            cout<<"10 x 0"<<endl;
        }
    int div7=amount/5;
    if(div7>0){
        amount=amount%5;
        if(amount>=0){
            cout<<"5 x "<< div7 <<endl;
        }
        else{
            cout<<"5 x 0"<<endl;
        }
    }
    else{
            cout<<"5 x 0"<<endl;
        }
    int div8=amount/2;
    if(div8>0){
        amount=amount%2;
        if(amount>=0){
            cout<<"2 x "<< div8 <<endl;
        }
        else{
            cout<<"2 x 0"<<endl;
        }
    }
    else{
            cout<<"2 x 0"<<endl;
        }
    int div9=amount/1;
    if(div9>0){
        amount=amount%1;
        if(amount>=0){
            cout<<"1 x "<< div9 <<endl;
        }
        else{
            cout<<"1 x 0"<<endl;
        }
    }
    return 0;
}