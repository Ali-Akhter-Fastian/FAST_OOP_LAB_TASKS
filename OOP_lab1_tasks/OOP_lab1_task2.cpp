//TASK # 02 by ALI AKHTER 24k-0809
#include<iostream>
using namespace std;
int main(){
    char a='A';
    int k=0,j,i,n;
    cout<<"Enter rows: ";
    cin>>n;
    n=(2*n)-2;
    int l=n-3;
    for(i=n;i>=0;i--){
        if(n%2==0){
            if(i>=n/2) l--;
            if(i==(n/2-1)) l++,k=n-2;
            if(i<(n/2-1)) l++,k=k-2;
        }
        else{
            if(i>=((n/2)+1)) l--;
            if(i==(((n/2)+1)-1)) l++,k=n-2;
            if(i<(((n/2)+1)-1)) l++,k=k-2;
        }
        for(j=0;j<=k+l;j++){
            if(j<l)    cout<<" ";
            else{
                cout<<a;
                a++;
            }
        }
        cout<<endl;
        a='A';
        if(i>=n/2)
        k=k+2;
    }
    return 0;
}