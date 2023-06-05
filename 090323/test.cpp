#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Base
{
public:
    virtual void render() = 0;
};

class Derived1 : public Base
{
    void render() override { std::cout << "Derived1" << std::endl; }
};

class Derived2 : public Base
{
    void render() override { std::cout << "Derived2" << std::endl; }
};

int main()
{
    std::vector<Base *> baseVec;
    Derived1 d;
    Derived2 d1;
    baseVec.push_back(&d);
    baseVec.push_back(&d1);

    for (auto &b : baseVec)
    {
        b->render();
        std::cout << typeid(*b).name() << std::endl;
    }

    return 0;
}