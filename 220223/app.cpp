#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Stack
{
private:
    int max_size = 100;
    int size = 0;
    int *stack = new int[max_size];

public:
    // метод добавляння елемента до стека
    void push(int item)
    {
        if (size > 9)
        {
            cout << "StackOverFlow" << endl;
            return;
        }
        stack[size++] = item;
    }
    // метод видалення елемента зі стека
    void pop()
    {
        if (size < 1)
        {
            cout << "Stack is empty" << endl;
        }
        stack[size--] = 0;
    }
    // метод повертання останнього елемента доданого в стека
    int top()
    {
        if (size < 1)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }

        return stack[size - 1];
    }
    // метод перевіряючий чи стек пустий
    bool empty()
    {
        if (size < 1)
        {
            return true;
        }
        return false;
    }
};
void StackTest()
{
    Stack stack;
    stack.push(777);
    stack.push(-256);
    assert(stack.top() == -256);
    stack.pop();
    assert(stack.top() == 777);
    assert(stack.empty() == false);
    stack.pop();
    assert(stack.empty() == true);
    cout << "All tests passed" << endl;
}
int main()
{
    Stack stack;
    stack.push(777);                                                  // добавлення 777
    stack.push(-256);                                                 // добавлення -256
    cout << "output the last added element: " << stack.top() << endl; // виведення останнього доданого елемента (-256)
    stack.pop();                                                      // видалення останнього доданого елемента (-256)
    cout << "output the last added element: " << stack.top() << endl; // виведення останнього елемента (777)
    cout << "is the stack empty: " << stack.empty() << endl;          // перевірка чи стек пустний (ні - 0)
    stack.pop();
    cout << "is the stack empty: " << stack.empty() << endl; // перевірка чи стек пустний (так - 1)
    StackTest();

    // stack<int> stack;
    // stack.push(21); // Значення, що поміщаються в стек, повинні мати ті ж самі дані, що і записані при оголошенні стеку
    // stack.push(22);
    // stack.push(24);
    // stack.push(25);
    // int num = 0;
    // stack.push(num);
    // stack.pop();
    // stack.pop();
    // stack.pop();

    // while (!stack.empty())
    // {
    //     cout << stack.top() << " ";
    //     stack.pop();
    // }

    return 0;
}