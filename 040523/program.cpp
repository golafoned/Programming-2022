#include <iostream>
#include <map>
#include <string>
using namespace std;
struct Book
{
    string title;
    string author;
};

struct Article
{
    string article;
    string author;
};

class Content
{
};
class Catalog
{
private:
    map<int, Book> books;
    map<int, Article> articles;

public:
};
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Прив";
    return 0;
}