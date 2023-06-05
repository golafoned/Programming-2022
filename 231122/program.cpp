using namespace std;
#include <iostream>
#include <string>
#include <math.h>
// class Car
// {
// public:
//     Car() : price(0), name(" "), color("red"){};
//     Car(int _price, string _name, string _color) : price(_price), name(_name), color(_color)
//     {
//     }
//     string getColor()
//     {
//         return color;
//     }
//     string getName()
//     {
//         return name;
//     }
//     void setName(string _name)
//     {
//         name = _name;
//     }
//     void SetPrice(int _price)
//     {
//         price = _price;
//     }

//     void Input()
//     {
//         cout << "Enter price: " << endl;
//         cin >> price;
//         cout << "Enter name: " << endl;
//         getline(cin, name);
//         cout << "Enter color: " << endl;
//         getline(cin, color);
//     }
//     void Print()
//     {
//         cout << "Price -- " << price << endl;
//         cout << "Name -- " << name << endl;
//         cout << "Color -- " << color << endl;
//     }

// private:
//     string name;
//     string color;
//     int price;
// };
// int main()
// {
//     Car car1(1000, "Shkoda", "majestic");
//     car1.Print();
// }

class Student
{
public:
    Student() : name("John"), group("pmi11"), id(10){};
    Student(string _name, string _group, int _id) : name(_name), group(_group), id(_id)
    {
    }
    string getName()
    {
        return name;
    }
    string getGroup()
    {
        return group;
    }
    int getId()
    {
        return id;
    }

    void setName(string _name)
    {
        name = _name;
    }

    void setGroup(string _group)
    {
        group = _group;
    }
    void setId(int _id)
    {
        id = _id;
    }
    void Input()
    {
        cout << "Enter group: " << endl;
        cin >> group;
        cout << "Enter name: " << endl;
        cin >> name;
        cout << "Enter id: " << endl;
        cin >> id;
    }
    void Print()
    {
        cout << "Group -- " << group << endl;
        cout << "Name -- " << name << endl;
        cout << "Id -- " << id << endl;
    }

private:
    string name;
    string group;
    int id;
};

void ArraySort(Student array[], int length)
{
    int j = 0;
    Student tmp;
    for (int i = 0; i < length; i++)
    {
        j = i;
        for (int k = i; k < length; k++)
        {
            if (array[j].getId() > array[k].getId())
            {
                j = k;
            }
        }
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}
int main()
{
    // group all lower case (!)
    //  student1 = John PMI11 10
    Student student1();
    // student2:
    Student student2("Bob", "pmi12", 666);
    int n;
    cout << "Enter students amount: " << endl;
    cin >> n;
    Student *array = new Student[n];
    for (int i = 2; i < n; i++)
    {
        array[i].Input();
    }

    cout << "_________________________________________" << endl;
    string name;
    string group;
    cout << "Enter student group: " << endl;
    cin >> group;
    cout << "Students from this group: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (array[i].getGroup() == group)
        {
            array[i].Print();
        }
    }
    cout << "__________________________________" << endl;
    cout << "Enter student name: " << endl;
    cin >> name;
    cout << "Students with this name: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (array[i].getName() == name)
        {
            array[i].Print();
        }
    }
    cout << "__________________________________" << endl;

    array[0].setId(333);
    ArraySort(array, n);
    cout << "Sorting::::::" << endl;
    for (int i = 0; i < n; i++)
    {
        array[i].Print();
        cout << "__" << endl;
    }
    return 0;
}