//Task # 02 by Ali Akhter 24k-0809
#include<iostream>
using namespace std;
class Product{
    private:
    string name;
    string category;
    double price;
    public:
    Product(){};
    Product(string name, string category, double price){
        this->name=name;
        this->category=category;
        this->price=price;
    }
    string getname(){return name;};
    string getcategory(){return category;};
    double getprice(){return price;};
};
class Store{
    private:
    string name;
    string location;
    Product *products;
    int Productscount;
    public:
    Store(){};
    Store(string name,string location,Product *products,int Productscount){
        this->name=name;
        this->location=location;
        this->Productscount=Productscount;
        products=products;
    }
    Store(string name, string location){
        this->name=name;
        this->location=location;
        this->Productscount=0;
        products=new Product[100];
    }
    void addProduct(Product &p){
        products[Productscount]=Product(p);
        Productscount++;
    }
    bool searchProduct(string namep){
        bool check=false;
        for(int i=0;i<Productscount;i++){
            if(products[i].getname()==namep){
                check=true;
                break;
            }
        }
        return check;
    }
    Product deleteProduct(){
        string deleteproduct;
        int index;
        bool check=true;
        cout<<"Enter name of product you want to delete from the list: "<<endl;
        cin>>deleteproduct;
        for(int i=0;i<Productscount;i++){
            if(products[i].getname()==deleteproduct){
                index=i;
                check=false;
                break;
            }
        }
        if(check){
            cout<<"Product not found!!!"<<endl;
        }
        else{
            Product p=products[index];
            for(int i=index;i<Productscount-1;i++){
                products[i]=products[i+1];
            }
            cout<<"Product deleted from the shop!!!"<<endl;
            Productscount--;
            return p;
        }
    }
    void DisplayAll(){
        cout<<"Store: "<<name<<endl;
        for(int i=0;i<Productscount;i++){
            cout<<"Product "<<i+1<<endl;
            cout<<"Name: "<<products[i].getname()<<endl;
            cout<<"Price: "<<products[i].getprice()<<endl;
            cout<<"Category: "<<products[i].getcategory()<<endl;
        }
    }
    string getName(){return name;};
};
class Company{
    private:
    string name;
    Store *stores;
    int stores_count;
    public:
    Company(){};
    Company(string name){
        this->name=name;
        this->stores_count=0;
    }
    void add_store(Store *store){
        if(stores_count>9){
            cout<<"Stores limit reached!!!"<<endl;
            return;
        }
            Store *temp=new Store[stores_count+1];

                for(int i=0;i<stores_count;i++){
                    temp[i]=stores[i];
                }
            temp[stores_count]=*store;
            if(stores_count!=0){

                delete[] stores;
            }
            stores=temp;
            stores_count++;
    }
    void searchProductsInStore(){
        int count=0;
        string name;
        cout<<"Enter name of product to search for:";
        cin>>name;
        for(int i=0;i<stores_count;i++){
            bool check=stores[i].searchProduct(name);
            if(check){
                count++;
            }
        }
        if(count==0){
            cout<<"Product not found in store!!!"<<endl;
        }
        else{
            cout<<"Product "<<name<<" found in "<<count<<" stores!!!"<<endl;
        }
    }
    void DispalyAll(){
        cout<<"Company: "<<name<<endl;
        cout<<"Stores"<<endl;
        for(int i=0;i<stores_count;i++){
            cout<<" -"<<stores[i].getName()<<endl;
        }
    }
};
int main(){
    Product p[3];
    p[0]=Product("SmartPhone","Electronics",900);
    p[1]=Product("Laptop","Electronics",1100);
    p[2]=Product("HeadPhone","Accessories,",150);
    Store s[2];
    s[0]=Store("ElectroShop","Hyderi");
    s[1]=Store("GadgetShop","Saddar");
    s[0].addProduct(p[1]);
    s[0].addProduct(p[2]);
    s[1].addProduct(p[0]);
    s[1].addProduct(p[1]);
    Company c("Tech Mart");
    c.add_store(&s[0]);
    c.add_store(&s[1]);
    c.DispalyAll();
    s[0].DisplayAll();
    s[1].DisplayAll();
    c.searchProductsInStore();
    Product deleted=s[0].deleteProduct();
    s[0].DisplayAll();
    return 0;
}