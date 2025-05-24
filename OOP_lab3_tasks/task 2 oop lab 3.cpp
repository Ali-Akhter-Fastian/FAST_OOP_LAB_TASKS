//TASK # 02 by ALI AKHTER 24k-0809
#include<iostream>
using namespace std;
class Circle{
	private:
		double radius;
		double pi=3.14159;
	public:
		void setRadius(double radius){
			this->radius=radius;
		}
		double getRadius(){
			return radius; 
		}
		double getArea(){
			double area=pi * radius * radius;
			return area;
		}
		double getDiameter(){
			double diameter=radius * 2;
			return diameter;
		}
		double getCircumference(){
			double circumference=2 * pi * radius;
			return circumference;
		}
};
int main(){
	Circle c1;
	double radius;
	cout<<"Enter radius: ";
	cin>>radius;
	c1.setRadius(radius);
	double radius1=c1.getRadius();
	cout<<"Radius: "<<radius1<<endl;
	double area=c1.getArea();
	cout<<"Area: "<<area<<endl;
	double diameter=c1.getDiameter();
	cout<<"Diameter: "<<diameter<<endl;
	double circumference=c1.getCircumference();
	cout<<"Circumference: "<<circumference<<endl;
	
}