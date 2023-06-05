#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
    string name;
    string address;
    bool operator>(const Person &other) const
    {
        return name > other.name;
    }
    bool operator<(const Person &other) const
    {
        return name < other.name;
    }
};

template <typename T>
void sortByName(vector<T> &v)
{
    sort(v.begin(), v.end());
}

int main()
{
    vector<int> v1 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    vector<string> v2 = {"cherry", "date", "apple", "banana", "elderberry"};
    vector<Person> v3 = {{"John", "123 Main St."}, {"Anna", "456 Elm St."}, {"Bob", "789 Oak St."}};

    sortByName(v1);
    sortByName(v2);
    sortByName(v3);

    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto s : v2)
    {
        cout << s << " ";
    }
    cout << endl;

    for (auto p : v3)
    {
        cout << p.name << " " << p.address << endl;
    }

    return 0;
}