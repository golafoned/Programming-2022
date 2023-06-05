#include <iostream>
#include <exception>
#include <string>
using namespace std;
class A
{
    int x;

public:
    A(int i) : x(i){};
    string g(int i)
    {
        if (i > x)
            throw "Overflow";
        return "Ok";
        if (i < 0)
            throw "Underflow";
    }
};
void F()
{
    try
    {
        A a(20);
        cout << a.g(-20);
    }
    catch (const string &e)
    {
        cout << "Out of range";
    }
    catch (...)
    {
        cout << "Fatal";
    }
    cout << ":)";
}

int main()
{
    F();
}