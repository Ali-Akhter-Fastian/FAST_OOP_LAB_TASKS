//TASK # 04 by ALI AKHTER 24k-0809
#include<iostream>
using namespace std;
int main(){
    int n,sum=0;
    cout<<"Enter size of matrix: ";
    cin>>n;
    int **matrix=new int*[n];
    for(int i=0;i<n;i++){
        matrix[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"matrix["<<i+1<<"x"<<j+1<<"]: ";
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(i==j){
    			sum=sum+matrix[i][j];
			}\
			if(i+j==n-1 && i!=j){
				sum=sum+matrix[i][j];
			}
		}
	}
	cout<<"sum of main and secondary diagnols= "<<sum<<endl;\
	for(int i=0;i<n;i++){
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}