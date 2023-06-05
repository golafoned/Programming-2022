/*
 *   Завдання: В текстовому файлі задано послідовність слів, розділених пропусками. Ввести слова в контейнер.
 *  Використовуючи алгоритми STL, кожне слово, яке починається і закінчується на одну і ту ж букву перемістити
 *  в інший контейнер. Утворити контейнер, який міститиме без повторів всі символи, що входять до складу даної
 *  послідовності слів
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    ifstream inputFile("input_to_task_1.txt"); // читання з файлу input.txt Прикладу вмісту файлу: "Hi it's example sentence with no meaning with words lol droid pop robber tron"
    if (!inputFile)
    {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }

    vector<string> words;
    string word;

    // читання слова з файлу
    while (inputFile >> word)
    {
        words.push_back(word);
    }

    // слова з однаковими початковими та кінцевими літерами
    vector<string> sameLettersWords;
    copy_if(words.begin(), words.end(), back_inserter(sameLettersWords),
            [](const string &w)
            {
                return !w.empty() && w.front() == w.back();
            });

    // Створення контейнера set з унікальних символів
    set<char> uniqueCharacters;
    for (const string &w : words)
    {
        uniqueCharacters.insert(w.begin(), w.end());
    }

    // Вивід слів які починаються і закінчуються однаково
    cout << "Words with the same starting and ending letters:" << endl;
    for (const string &w : sameLettersWords)
    {
        cout << w << endl;
    }

    // Вивід унікальних символів
    cout << "Unique characters from the words:" << endl;
    for (char c : uniqueCharacters)
    {
        cout << c << ' ';
    }
    cout << endl;

    return 0;
}
