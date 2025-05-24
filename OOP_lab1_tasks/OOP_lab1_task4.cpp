//TASK # 04 by ALI AKHTER 24k-0809
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of arrays: ";
    cin>>n;
    int arr1[n],arr2[n];
    cout<<"Enter 5 elements of first array: ";
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<"Enter 5 elements of second array: ";
     for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    for(int i=0;i<n;i++){
        int temp=arr1[i];
        arr1[i]=arr2[i];
        arr2[i]=temp;
    }
    cout<<"Arrays after swapping"<<endl;
    cout<<"First Array:";
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"Second Array:";
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }
    int max=-999999,smax=-99999;
    for(int i=0;i<n;i++){
        if(arr1[i]>max){
            max=arr1[i];
        }
    }
    cout<<endl<<endl;
    cout<<"Largest element in first array (after swapping): "<<max<<endl;
    max=-999999;
     for(int i=0;i<n;i++){
        if(arr2[i]>max){
            smax=max;
            max=arr2[i];
        }
        else if(arr2[i]<max && arr2[i]>smax){
            smax=arr2[i];
        }
    }
    cout<<"Second largest element in second array (after swapping): "<<smax<<endl;
    int count=0;
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(arr1[i]==arr1[j] && i!=j){
                count++;
                break;
            }
        }
        if(count==0){
            cout<<"Unique element in first array "<<arr1[i]<<endl;
            count=-1;
            break;
        }
    }
    if(count!=-1){
        cout<<"No unique element, The element at index 0 is "<<arr1[0]<<endl;
    }
    return 0;
} 


