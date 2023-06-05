#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Person
{
public:
    // bool compare()
    virtual void input(istream &is)
    {
        is >> age >> name;
    }
    virtual void output(ostream &os)
    {
        os << "Age: " << age << " ;Name: " << name;
    }
    friend istream &operator>>(istream &is, Person &data)
    {
        data.input(is);
        return is;
    }
    friend ostream &operator<<(ostream &os, Person &data)
    {
        data.output(os);
        return os;
    }

protected:
    string name;
    int age;
};

class Student : public Person
{
private:
    string group_number;
    int scholarship;

public:
    void input(istream &is)
    {
        Person::input(is);
        is >> group_number >> scholarship;
    }
    void output(ostream &os)
    {
        Person::output(os);
        os << "Group: " << group_number << "; Scholarship: " << scholarship;
    }
    string GetGroupNumber()
    {
        return group_number;
    }
    int GetScholarship()
    {
        return scholarship;
    }
};

class Worker : public Person
{
private:
    int wage;

public:
    void input(istream &is)
    {
        Person::input(is);
        is >> wage;
    }
    void output(ostream &os)
    {
        Person::output(os);
        os << "Wage: " << wage;
    }
};
int main()
{
    vector<Person *> list;
    string data;
    ifstream myfile("data.txt");
    while (myfile.eof())
    {
        int num;
        Person *temp;
        myfile >> num;
        if (num == 1)
        {
            temp = new Student();
        }
        if (num == 2)
        {
            temp = new Worker();
        }
        cout << 1;
        temp->input(myfile);
        list.push_back(temp);
    }
    if (myfile.is_open())
    {
        myfile >> data;
        cout << data;
    }
    return 0;
}