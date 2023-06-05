#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

template <typename T>
class Goods
{
public:
    T object;
    string manufacture_date;
    string expire_date;
    int days_to_expire;

    friend ostream &operator<<(ostream &os, const Goods<T> &goods)
    {
        os << goods.object << ";\t Expire Date: " << goods.expire_date;
        return os;
    }

    friend istream &operator>>(istream &is, Goods<T> &goods)
    {
        cout << "Enter good data:" << endl;
        is >> goods.object;
        cout << "Days to expire: ";
        is >> goods.days_to_expire;
        time_t t = time(nullptr);
        char mbstr[100];
        if (strftime(mbstr, sizeof(mbstr), "%d-%m-%Y", localtime(&t)))
        {
            goods.manufacture_date = mbstr;
        }
        time_t t2 = time(nullptr) + 86400 * goods.days_to_expire;
        char mbstr2[100];
        if (strftime(mbstr2, sizeof(mbstr2), "%d-%m-%Y", localtime(&t2)))
        {
            goods.expire_date = mbstr2;
        }

        return is;
    }
};

struct Milk
{
    string name;
    double fat_content;

    friend ostream &operator<<(ostream &os, const Milk &milk)
    {
        os << "Milk Name: " << milk.name << "; Milk Fat Content: " << milk.fat_content << "%";
        return os;
    }

    friend istream &operator>>(istream &is, Milk &milk)
    {
        cout << "Enter Milk Name: ";
        is >> milk.name;
        cout << "Enter Milk Fat Content (%): ";
        is >> milk.fat_content;
        return is;
    }
};

int main()
{
    vector<Goods<string>> string_goods(2);
    vector<Goods<Milk>> milk_goods(2);

    for (auto &good : string_goods)
    {
        cin >> good;
    }

    for (auto &good : milk_goods)
    {
        cin >> good;
    }

    for (auto good : string_goods)
    {
        cout << good << endl;
    }

    for (auto good : milk_goods)
    {
        cout << good << endl;
    }

    return 0;
}