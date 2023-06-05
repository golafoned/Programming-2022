
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<char> latin_letters_and_numbers;
    list<char> non_latin_chars;

    string input_str;
    cout << "Enter a sequence of characters: ";
    getline(cin, input_str);

    for (char &ch : input_str)
    {
        if (isalnum(ch))
        {
            if (find(latin_letters_and_numbers.begin(), latin_letters_and_numbers.end(), ch) == latin_letters_and_numbers.end())
            {
                latin_letters_and_numbers.push_back(ch);
            }
        }
        else
        {
            if (find(non_latin_chars.begin(), non_latin_chars.end(), ch) == non_latin_chars.end())
            {
                non_latin_chars.push_back(ch);
            }
        }
    }

    non_latin_chars.sort();
    non_latin_chars.unique();

    cout << "Latin letters and numbers: ";
    for (char &ch : latin_letters_and_numbers)
    {
        cout << ch << " ";
    }
    cout << endl;

    cout << "Non-Latin characters: ";
    for (char &ch : non_latin_chars)
    {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}