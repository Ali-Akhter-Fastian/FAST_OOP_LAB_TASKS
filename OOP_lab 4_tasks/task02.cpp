// TASK # 02 by Ali Akhter 24k-0809
#include <iostream>
using namespace std;
class product
{
private:
    int ID;
    string name;
    double price;
    int StockQuantity;
    int ProductQuantity;

public:
    product(int ID, string name, double price, int StockQuantity)
    {
        this->ID = ID;
        this->name = name;
        this->price = price;
        this->StockQuantity = StockQuantity;
    }
    product() {};
    void ReduceStock(int PurchasedQuantity)
    {
        StockQuantity -= PurchasedQuantity;
    }
    int getID()
    {
        return ID;
    }
    string getName()
    {
        return name;
    }
    double getPrice()
    {
        return price;
    }
    void setProductQuantity(int Quantity)
    {
        this->ProductQuantity = Quantity;
    }
    int getStockQuantity()
    {
        return StockQuantity;
    }
    int getProductQuantity() { return ProductQuantity; }
};
class ShoppingCart
{
private:
    double bill;
    int CartItemCount;
    product **Cart;

public:
    ShoppingCart(int numberOfItems) : Cart(new product *[numberOfItems]), CartItemCount(0) {};
    ShoppingCart()
    {
    }
    void addProduct(product *Product, int numItems)
    {
        int ID;
        cout << "Enter product ID: ";
        cin >> ID;
        int Quantity;
        cout << "Enter Quantity ";
        cin >> Quantity;
        for (int i = 0; i < numItems; i++)
        {
            if (Product[i].getID() == ID)
            {
                if (Product[i].getStockQuantity() >= Quantity)
                {
                    Cart[CartItemCount] = new product(Product[i]);
                    Cart[CartItemCount]->setProductQuantity(Quantity);
                    Product[i].ReduceStock(Quantity);
                    CartItemCount++;
                }
                else
                {
                    cout << "Sorry! Product is out of stock" << endl;
                    return;
                }
            }
        }
    }
    void CalculateBill(){
        bill=0;
        for(int i=0;i<CartItemCount;i++){
            bill+=(Cart[i]->getPrice()*Cart[i]->getProductQuantity());
        }
    }
    void RemoveProduct(){
        int RemID;
        cout<<"Enter ID of Product to remove: ";
        cin>>RemID;
        int flag=0,removedindex;
        for(int i=0;i<CartItemCount;i++){
            if(Cart[i]->getID()==RemID){
                flag++;
               delete Cart[i]; 
               cout<<"Item successfully deleted from the cart!!"<<endl;
               removedindex=i;
            }
        }
        if(flag=0){
            cout<<"Item not found!!"<<endl;
            return;
        } 
        for(int i=removedindex;i<CartItemCount-1;i++){
            Cart[i]=Cart[i+1];  //shifting products backward
        }
        product **temp;
        temp=new product *[CartItemCount-1];
        for(int i=0;i<CartItemCount-1;i++){
            temp[i]=Cart[i];
        }
        delete[] Cart;
        Cart=temp;
        CartItemCount--;
    }
    void DisplayCart()
    {
        for (int i = 0; i < CartItemCount; i++)
        {
            cout << "     ~~Product: " << i + 1 << "~~     " << endl;
            cout << "ID: " << Cart[i]->getID() << endl;
            cout << "Name: " << Cart[i]->getName() << endl;
            cout << "Quantity: " << Cart[i]->getProductQuantity() << endl;
        }
    }
    void CheckOut(){
        cout<<"Checking Out!!"<<endl;
        string name;
        cout<<"Enter Coustomer's name: ";
        cin>>name;
        CalculateBill();
        cout<<name<<" your total bill is RS: "<<bill<<endl;
    }
};
int main()
{
    int numProducts = 6;
    product ShopProducts[numProducts];
    int ProductCount = 0;
    ShopProducts[ProductCount] = product(1, "Orange", 500, 5000);
    ProductCount++;
    ShopProducts[ProductCount] = product(2, "Mango", 1000, 0);
    ProductCount++;
    ShopProducts[ProductCount] = product(3, "Brinjal", 100, 2);
    ProductCount++;
    ShopProducts[ProductCount] = product(4, "Strawberry", 800, 1000);
    ProductCount++;
    ShopProducts[ProductCount] = product(5, "Potato", 150, 10000);
    ProductCount++;
    ShopProducts[ProductCount] = product(6, "Onion", 180, 0);
    int CartSize;
    cout << "~Available Products~" << endl;
    for (int i = 0; i < numProducts; i++)
    {
        cout << "ID: " <<ShopProducts[i].getID() << ", Name: " << ShopProducts[i].getName()
             << ", Price: $" << ShopProducts[i].getPrice() << ", Stock: " << ShopProducts[i].getStockQuantity() << endl;
    }
    cout << "Enter the max ize of your Cart: ";
    cin >> CartSize;
    ShoppingCart C1(CartSize);
    C1.addProduct(ShopProducts, ProductCount);
    C1.addProduct(ShopProducts, ProductCount);
    C1.addProduct(ShopProducts, ProductCount);
    C1.RemoveProduct();
    C1.DisplayCart();
    C1.CheckOut();
    return 0;
}
