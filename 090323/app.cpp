#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Computer
{
public:
    string company;
    double price;
    double getPrice()
    {
        return price;
    }
    string getCompany()
    {
        return company;
    }
    virtual void Output(ofstream &file) = 0;
};

class Stationary : public Computer
{
public:
    string type;

    virtual void Output(ofstream &file) override
    {
        file << company << " " << price << " " << type << endl;
    }
};
class Laptop : public Computer
{
public:
    double diagonal;
    int memory;

    virtual void Output(ofstream &file) override
    {
        file << company << " " << price << " " << diagonal << " " << memory << endl;
    }
};
void swap(Computer &c1, Computer &c2)
{
    Computer &temp = c1;
    c1 = c2;
    c2 = temp;
}
void bubbleSort(vector<Computer *> &arr)
{
    int n = arr.size();
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j]->getPrice() > arr[j + 1]->getPrice())
                swap(arr[j], arr[j + 1]);
}
int main()
{
    ifstream infile("computers.txt");
    vector<Computer *> computers;
    string type;

    while (infile >> type)
    {
        if (type == "Stationary")
        {
            Stationary *s = new Stationary();
            infile >> s->company >> s->price >> s->type;
            computers.push_back(s);
        }
        else if (type == "Laptop")
        {
            Laptop *l = new Laptop();
            infile >> l->company >> l->price >> l->diagonal >> l->memory;
            computers.push_back(l);
        }
    }

    bubbleSort(computers);
    double total_price;
    for (int i = 0; i < computers.size(); i++)
    {
        total_price += computers[i]->getPrice();
    }
    ofstream outputFile("output.txt");
    if (outputFile.is_open())
    {
        outputFile << "Sorted by price computers:" << endl;
        for (int i = 0; i < computers.size(); i++)
        {
            outputFile << i + 1 << ". ";
            computers[i]->Output(outputFile);
        }
        outputFile << "\n\nTotal price = " << total_price << "$" << endl;
        outputFile << "\nAll Dell's Stationary:" << endl;
        for (int i = 0; i < computers.size(); i++)
        {
            if (dynamic_cast<Stationary *>(computers[i]) && computers[i]->getCompany() == "Dell")
            {
                computers[i]->Output(outputFile);
            }
        }

        outputFile.close();
    }
    else
    {
        cout << "Error" << endl;
    }
    return 0;
}