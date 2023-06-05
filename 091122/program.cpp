#include <iostream>
using namespace std;
bool isInText(string str, char letter, int end_pos);
int countChar(string str, char letter, int l);

int main()
{
    string str = "";
    cout << "Enter text: " << endl;
    getline(cin, str);
    isInText(str, 's', 10);
    for (int i = 0; i < str.size(); i++)
    {
        if (!isInText(str, str[i], i - 1))
        {
            cout << str[i] << '-' << countChar(str, str[i], i);
        }
    }
}