#include<iostream>
using namespace std;
int SumArr(int *arr1, int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=*(arr1+i);
    }
    return sum;
}
int main(){
    int size;
    cout<<"Enter size of array: ";\
    cin>>size;
    int arr[size];
    cout<<"Enter values: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int sumofarr=SumArr(arr,size);
    cout<<"The sum of array is: "<<sumofarr<<endl;
    return 0;
}