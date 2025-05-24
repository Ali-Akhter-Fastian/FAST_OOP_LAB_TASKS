//TASK # 03 by ALI AKHTER 24k-0809
#include<iostream>
using namespace std;
class waterbottle{
	private:
		string company;
		string colour;
		double capacityinml;
		double capacityinl;
	public:
	   waterbottle(){
		this->company="Null";
		this->colour="Null";
		this->capacityinl=0;
		this->capacityinml=0;
	   }
		void setInfo(string company , string colour , double capacity){
			this->company=company;
			this->colour=colour;
			this->capacityinml=capacity;
			this->capacityinl=capacity/1000;
		}
		void update(double amount){
			capacityinml-=amount;
			 amount=amount/1000;
			 capacityinl-=amount;
		}
		string getCompany(){
			return company;
		}
		string getcolour(){
			return colour;
		}
		double getCapacityInml(){
			return capacityinml;
		}
		double getCapacityInl(){
			return capacityinl;
		}
};
int main(){
	waterbottle w1;
	w1.setInfo("Nestle","Blue",500);
	string company=w1.getCompany();
	cout<<"Company: "<<company<<endl;
	string colour=w1.getcolour();
	cout<<"Colour: "<<colour<<endl;
	double capacityml=w1.getCapacityInml();
	cout<<"Capacity in ml: "<<capacityml<<"ml"<<endl;
	double capacityl=w1.getCapacityInl();
	cout<<"Capacity in Litres: "<<capacityl<<"l"<<endl;
	double amount;
	cout<<endl<<"Enter the amount of water drunk: ";
	cin>>amount;
	w1.update(amount);
	cout<<endl<<"Water capacity after drinking"<<endl;
	capacityml=w1.getCapacityInml();
	cout<<"Capacity in ml: "<<capacityml<<"ml"<<endl;
	capacityl=w1.getCapacityInl();
	cout<<"Capacity in Litres: "<<capacityl<<"l"<<endl;
}