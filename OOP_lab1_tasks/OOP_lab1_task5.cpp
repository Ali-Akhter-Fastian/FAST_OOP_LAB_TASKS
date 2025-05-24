//TASK # 05 by ALI AKHTER 24k-0809
#include<iostream>
using namespace std;
void multiplyMatrices(){
     int m,n,o,p;
    cout<<"Enter rows and columns of first matrix: ";
    cin>>m>>n;
    cout<<"Enter rows and columns of second matrix: ";
    cin>>o>>p;
    int arr1[m][n],arr2[o][p];
    if(n!=o){
       cout<<"The product is not possible";
       return;
    }
    cout<<"Enter values of 1st matrix"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
        }
    }
    cout<<"Enter values of 2nd matrix"<<endl;
    for(int i=0;i<o;i++){
        for(int j=0;j<p;j++){
            cin>>arr2[i][j];
        }
    }
    int result[m][p];
    for(int i=0;i<m;i++){   //initializing result matrix 
        for(int j=0;j<p;j++){
            result[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            for(int k=0;k<n;k++){
                result[i][j]+=((arr1[i][k])*(arr2[k][j]));
            }
        }
    }
    cout<<"The product of matrices provides is: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    multiplyMatrices();
    return 0;
}