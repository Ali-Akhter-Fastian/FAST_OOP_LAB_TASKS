// TASK # 02 by Ali Ahmed Burney 24k-0719

#include <iostream>
using namespace std;

class Product
{
    int id;
    string name;
    double price;
    int stockQuant;
    int purchasedQuant;

public:
    Product() {}
    Product(int id, string name, double price, int stockQuant)
    {

        this->id = id;
        this->name = name;
        this->price = price;
        this->stockQuant = stockQuant;
    }
    void setPurchasedQuant(int quant)
    {

        purchasedQuant = quant;
    }

    // Getters to access private members
    int getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }
    int getStockQuant() { return stockQuant; }
    int getPurchasedQuant()
    {

        return purchasedQuant;
    }

    void reduceQuant(int quant)
    {
        stockQuant -= quant;
        // cout << " Stock: " << stockQuant;
    }
};

class ShoppingCart
{
    string userName;
    double bill;
    int purchasedQuant;
    bool cartStatus;
    Product **products;
    int cartProductsCount;

public:
    ShoppingCart() : products(nullptr), cartProductsCount(0)
    {}

    ShoppingCart(int productCount) : products(new Product *[productCount]), cartProductsCount(0), bill(0) {}

    ~ShoppingCart()
    {

        for (int i = 0; i < cartProductsCount; i++)
        {
            delete products[i]; // Delete each product object
        }
        delete[] products; // Delete the array of pointers
    }

    void setUserName(string name)
    {
        userName = name;
    }

    void addToCart(Product *p, int numOfItems)
    {
        int id;
        cout << "Enter the id of the product: ";
        cin >> id;

        cout << "Enter the quantity you want to buy: ";
        cin >> purchasedQuant;

        for (int i = 0; i < numOfItems; i++)
        {
            if (p[i].getId() == id)
            {
                if (p[i].getStockQuant() >= purchasedQuant)
                {
                    p[i].setPurchasedQuant(purchasedQuant);
                    Product **temp = new Product *[cartProductsCount + 1];

                    for (int j = 0; j < cartProductsCount; j++)
                    {
                        temp[j] = products[j];
                    }

                    // adding the product to the cart
                    temp[cartProductsCount] = new Product(p[i]);
                    temp[cartProductsCount]->reduceQuant(purchasedQuant);

                    delete[] products; // deleted previous address stored in it

                    products = temp;
                    cartProductsCount++;
                    cout << "Product added to the cart!" << endl;
                    return;
                }
                else
                {
                    cout << "Out of stock!!" << endl;
                    return;
                }
            }
        }
        cout << "Product not found!" << endl;
    }

    void remove()
    {
        if (cartProductsCount == 0)
        {
            cout << "The cart is empty!" << endl;
            return;
        }

        int id;
        cout << "Enter the id of the product to remove: ";
        cin >> id;

        // Find the product in the cart
        int indexToRemove = -1;
        for (int i = 0; i < cartProductsCount; i++)
        {
            if (products[i]->getId() == id)
            {
                indexToRemove = i;
                break;
            }
        }

        if (indexToRemove == -1)
        {
            cout << "Item not found in the cart!!" << endl;
            return;
        }

        delete products[indexToRemove];

        // Shift elements to the left to remove the product
        for (int i = indexToRemove; i < cartProductsCount - 1; i++)
        {
            products[i] = products[i + 1];
        }

        cartProductsCount--; // to reduce the size of cart

        // Resize the cart array
        Product **temp = new Product *[cartProductsCount];
        for (int i = 0; i < cartProductsCount; i++)
        {
            temp[i] = products[i];
        }

        delete[] products; // Delete the old cart array
        products = temp;   // Assign the new array to the cart pointer

        cout << "Product removed from the cart!" << endl;
    }

    void display()
    {
        for (int i = 0; i < cartProductsCount; i++)
        {
            cout << "ID: " << products[i]->getId() << ", Name: " << products[i]->getName()
                 << ", Price: " << products[i]->getPrice() << ", Quantity: " << products[i]->getPurchasedQuant() << endl;
        }
    }
    void calculateTotalPrice()
    {
        bill = 0;
        for (int i = 0; i < cartProductsCount; i++)
        {
            bill += products[i]->getPrice() * products[i]->getPurchasedQuant();
        }
    }

    void check_out()
    {
        cout << endl
             << "Checking out !" << endl;
        calculateTotalPrice();
        cout << endl
             << "Name: " << userName << endl
             << "Total bill : " << bill;
    }
};

int main()
{
    const int MAX_PRODUCTS = 10;    // Maximum number of products
    Product products[MAX_PRODUCTS]; // Array to store products
    int productCount = 0;           // Track the number of products added

    // Adding products to the array
    products[productCount++] = Product(1, "Laptop", 1200.50, 10);
    products[productCount++] = Product(2, "Smartphone", 799.99, 25);
    products[productCount++] = Product(3, "Headphones", 149.99, 50);
    products[productCount++] = Product(4, "Tablet", 499.99, 4);
    products[productCount++] = Product(5, "Smartwatch", 199.99, 30);

    // Display the menu of products
    cout << "~Available Products~" << endl;
    for (int i = 0; i < productCount; i++)
    {
        cout << "ID: " << products[i].getId() << ", Name: " << products[i].getName()
             << ", Price: $" << products[i].getPrice() << ", Stock: " << products[i].getStockQuant() << endl;
    }

    // Create a shopping cart
    int status;
    cout << "\nIs your cart empty or filled(Enter '1' for filled and '0'for not filled): ";
    cin >> status;

    if (status == 1)
    {
        ShoppingCart cart();
        cout << "Your cart is already filled!!";
        return 0;
    }

    else
    {
        string name;

        cout << "Enter your name: ";
        cin >> name;

        int numOfProducts;
        cout << "Enter the max number of products you want to add in the cart: ";
        cin >> numOfProducts;
        ShoppingCart cart(numOfProducts);
        cart.setUserName(name);

        int choice;
        do
        {
            // Display the menu
            cout << "\n~Menu~" << endl;
            cout << "1. Add a product to the cart" << endl;
            cout << "2. Remove a product from the cart" << endl;
            cout << "3. Display the cart" << endl;
            cout << "4. Check out!" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cart.addToCart(products, productCount);
                break;
            case 2:
                cart.remove();
                break;
            case 3:
                cout << "\n~Cart~" << endl;
                cart.display();
                break;
            case 4:
                cart.check_out();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 4);

        return 0;
    }
}