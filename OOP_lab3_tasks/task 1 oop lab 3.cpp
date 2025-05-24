//TASK # 01 by ALI AKHTER 24k-0809 
#include<iostream>
using namespace std;
class BoardMarker{
	private:
		string company;
		string color;
		bool refillable;
		bool inkStatus;
	public:
		void Setinfo(string company , string color , bool refillable , bool inkStatus){
			this->company=company;
			this->color=color;
			this->refillable=refillable;
			this->inkStatus=inkStatus;
		}
		string getCompany(){
			return company;
		}
		string getColor(){
			return color;
		}
		bool getRefillable(){
			return refillable;
		}
		bool getInkStatus(){
			return inkStatus;
		}
		void write(){
			if(inkStatus){
				cout<<"Proceed with writing"<<endl;
			}
			else
				cout<<"Writing is not possible"<<endl;
		}
		void refill(){
			if(refillable){
				refillable=false;
				cout<<"Ink status updated"<<endl;
			}
			else{
				cout<<"Ink can not be refilled"<<endl;
			}
		}
};
int main(){
	BoardMarker b1;
	BoardMarker b2;
	BoardMarker b3;
	b1.Setinfo("Dollar","Black",false,true);
	cout<<"~~Marker 1~~"<<endl;
	string Company;
	Company=b1.getCompany();
	cout<<"Company: "<<Company<<endl;
	string color;
	color=b1.getColor();
	cout<<"Color: "<<color<<endl;
	bool Refillable;
	Refillable=b1.getRefillable();
	if(Refillable){
		cout<<"Refillable: YES"<<endl;
	}
	else{
		cout<<"Refillable: NO"<<endl;
	}
	bool InkStatus;
	InkStatus=b1.getInkStatus();
	if(InkStatus){
		cout<<"InkStatus: Filled"<<endl;
	}
	else{
		cout<<"InkStatus: Empty"<<endl;
	}
	b1.write();
	b1.refill();
	cout<<"~~Marker 2~~"<<endl;
	b2.Setinfo("Mercury","Blue",true,false);
	Company=b2.getCompany();
	cout<<"Company: "<<Company<<endl;
	color=b2.getColor();
	cout<<"Color: "<<color<<endl;
	Refillable=b2.getRefillable();
	if(Refillable){
		cout<<"Refillable: YES"<<endl;
	}
	else{
		cout<<"Refillable: NO"<<endl;
	}
	InkStatus=b2.getInkStatus();
	if(InkStatus){
		cout<<"InkStatus: Filled"<<endl;
	}
	else{
		cout<<"InkStatus: Empty"<<endl;
	}
	b2.write();
	b2.refill();
	cout<<"~~Marker 3~~"<<endl;
	b3.Setinfo("Brito","red",true,false);
	Company=b3.getCompany();
	cout<<"Company: "<<Company<<endl;
	color=b3.getColor();
	cout<<"Color: "<<color<<endl;
	Refillable=b3.getRefillable();
	if(Refillable){
		cout<<"Refillable: YES"<<endl;
	}
	else{
		cout<<"Refillable: NO"<<endl;
	}
	InkStatus=b3.getInkStatus();
	if(InkStatus){
		cout<<"InkStatus: Filled"<<endl;
	}
	else{
		cout<<"InkStatus: Empty"<<endl;
	}
	b3.write();
	b3.refill();
}