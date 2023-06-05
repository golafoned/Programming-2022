/*
 *    Завдання: а) Дана функція f повинна змінити контейнер l1  таким чином: всі символи, які представляють цифри
 *    замінити на символ a. Дописати який саме <Алгоритм> треба використати і визначити необхідний
 *    функціональний об`єкт Fun, який використовується у вказаному алгоритмі для  виконання завдання.
 *
 *    void f(vector<char> l1, char  a)
 *
 *    {
 *
 *       //Task A
 *            <Алгоритм>(l1.begin(),l1.end(),l1.begin(), Fun(a));
 *
 *       //Task Б
 *
 *    }
 *
 *    Б) Використовуючи алгоритми STL , Дописати функцію так:  з контейнера l1 видалити всі елементи, які повторюються, залишивши лише по одному екземпляру. Вивести у потік змінений контейнер.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct Fun
{
    char replacement; // символ яким будемо заміняти цифри

    Fun(char repl) : replacement(repl) {} // конструктор

    bool operator()(char c) // перевіряємо чи char є числом
    {
        return isdigit(c);
    }
};

void f(vector<char> &l1, char a)
{
    // Task A
    replace_if(l1.begin(), l1.end(), Fun(a), a); // замінюємо всі символи які відповідають умові на змінну a
    cout << "After changing numbers: ";
    for (char c : l1) // виводимо контейнер після заміни в консоль
    {
        cout << c << ' ';
    }
    cout << endl;

    // Task B
    sort(l1.begin(), l1.end());             // сормуємо символи в vector для роботи алгоритма unique
    auto it = unique(l1.begin(), l1.end()); // видалення повторюваних елементів, що йдуть підряд
    l1.erase(it, l1.end());                 // витираємо повторювані елементи з l1.
}

int main()
{
    vector<char> l1 = {'1', 'a', '2', 'b', '3', 'c', 'a', 'b', '9', '0', 'r', 'p'}; // приклад вектора з символами
    char a = '*';

    cout << "Before: ";
    for (char c : l1)
    {
        cout << c << ' ';
    }
    cout << endl;

    f(l1, a);

    cout << "After deleting: ";
    copy(l1.begin(), l1.end(), ostream_iterator<char>(cout, " ")); // виводимо у потік змінений після видалення елементів вектор
    cout << endl;

    return 0;
}
