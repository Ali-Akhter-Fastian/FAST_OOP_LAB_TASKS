//TASK # 04 by ALI AKHTER 24k-0809
#include<iostream>
#include<string>
using namespace std;
class Stationary{
    private:
        string items[50];
        double itemPrices[50];
    public:
    	Stationary(){
    	 	for(int i=0;i<50;i++){
                 this->items[i]="Null"; //Initializing items array to avoid garbage value issues
                 this->itemPrices[i]=0; //Initializing prices array to avoid garbage value issues
		 	}
		 }
        void AddItem(){
            int n;
            cout<<"Enter number of items to be added: ";
            cin>>n;
            for(int i=0;i<50;i++){
                if(this->items[i]=="Null" && this->itemPrices[i]==0 && n>=0){
                cout<<"Enter item "<<i+1<<" of your shop: ";
                cin>>this->items[i];
                cout<<"price: ";
                cin>>this->itemPrices[i];
                n--;
                }
                if(n==0)    break;
            }
        }
        void ViewItemsList(){
            cout<<"   ~~~The Item list of your shop~~~"<<endl;
            for(int i=0;i<50;i++){
                if(this->items[0]=="Null") cout<<"Items list is Empty"<<endl<<endl<<endl;
                if(this->items[i]=="Null")  break;
                cout<<i+1<<"->"<<this->items[i]<<endl;
            }
        }
        void EditPrice(){
            int n;
            cout<<"Enter serial number of item to be edited: ";
            cin>>n;
            if(this->items[n-1]=="Null")    cout<<"Item is not present"<<endl;
            else{
            double price;
            cout<<"Enter new price: ";
            cin>>price;
            this->itemPrices[n-1]=price;
            }
        }
        void ViewItemsWithPrices(){
            cout<<"   ~~~Items list with their prices~~~"<<endl;
            for(int i=0;i<50;i++){
                if(this->items[0]=="Null")  cout<<"List is empty";
                if(this->items[i]=="Null")  break;
                cout<<i+1<<"->"<<this->items[i]<<endl<<"     Price:"<<this->itemPrices[i]<<endl;
            }
        }
        void generateReceipt(){
            cout<<"Generating Receipt"<<endl;
            string name;
            cout<<"Coustomer's name: ";
            cin>>name;
            string purchased;
            cout<<"Item Purchased: ";
            cin>>purchased;
            int n;
            cout<<"Quantity: ";
            cin>>n;
            cout<<"~~~Your Receipt is here~~~"<<endl<<endl;
            for(int i=0;i<50;i++){
                if(this->items[i]==purchased){
                    cout<<"  Name: "<<name<<endl;
                    cout<<"  Item name= "<<this->items[i]<<endl;
                    int totalprice;
                    totalprice=this->itemPrices[i]*n;
                    cout<<"  Total Price= "<<totalprice<<endl;
                }
            }
        }
};
int main(){
 Stationary s1;
 s1.ViewItemsList();
 s1.AddItem();
 s1.ViewItemsList();
 s1.ViewItemsWithPrices();
 s1.EditPrice();
 s1.ViewItemsWithPrices();
 s1.generateReceipt();
 return 0;
}