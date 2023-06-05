#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Card
{
};
class Product
{
private:
    int price;
    int code;
    string name;

public:
    int getPrice()
    {
        return price;
    }
    int getCode()
    {
        return code;
    }
    string getName()
    {
        return name;
    }
    friend istream &operator>>(istream &is, Product &product)
    {
        is >> product.price >> product.name >> product.code;
        return is;
    }
};
class Cart
{
private:
    Product *Products_;
    int *Count;
    int current;

public:
    Cart() : current(0)
    {
        Products_ = new Product[100];
        Count = new int[100];
    }
    void AddProd(Product item, int count)
    {
        // current += count;
        for (int i = 0; i < count; i++)
        {
            Products_[current] = item;
            current++;
        }
        // Count[current] = count;
    }
    void RemoveProd(Product product)
    {
        bool isRemoved = false;
        for (int i = 0; i < current; i++)
        {
            if (Products_[current].getCode() == product.getCode() && !isRemoved)
            {
                cout << "sssssssss";
                Products_[current] = Products_[current + 1];
                isRemoved = true;
                current--;
            }
            else if (isRemoved)
            {
                Products_[current] = Products_[current + 1];
            }
        }
    }
    void DisplayCart()
    {
        for (int i = 0; i < current; i++)
        {
            cout << "Product: " << Products_[i].getName() << "; Code: " << Products_[i].getCode() << "; Price: " << Products_[i].getPrice() << endl;
        }
    }
};
int main()
{
    Product prod1;
    Product prod2;
    cout << "Enter 1st product params:" << endl;
    cin >> prod1;
    cout << "Enter 2nd product params:" << endl;
    cin >> prod2;
    // cout << prod1.getPrice() << endl;
    Cart cart;
    cart.AddProd(prod1, 3);
    cart.AddProd(prod2, 4);
    cout << "Your Cart:" << endl;
    cart.DisplayCart();
    cart.RemoveProd(prod1);
    cout << "Your Cart After Remove:" << endl;
    cart.DisplayCart();
    return 0;
}