#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
vector<T> split_array(vector<T> arr)
{
    if (arr.empty())
    {
        throw runtime_error("Empty array");
    }

    T last = arr.back();

    vector<T> greater, less_equal;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > last)
        {
            greater.push_back(arr[i]);
        }
        else
        {
            less_equal.push_back(arr[i]);
        }
    }

    if (greater.size() < less_equal.size())
    {
        return greater;
    }
    else
    {
        return less_equal;
    }
}

template <typename T>
void print_vector(vector<T> v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> nums = {5, 3, 7, 2, 9, 4, 6, 3, 12, 5, 3, 7, 0, 5};

    vector<string> words = {"apple", "shoes", "laptop", "ball", "zoo", "horse", "auto", "male", "penny", "whale", "nato"};

    try
    {
        vector<int> result1 = split_array(nums);
        cout << "The result for the array of integers is: ";
        print_vector(result1);

        vector<string> result2 = split_array(words);
        cout << "The result for the array of strings is: ";
        print_vector(result2);
    }
    catch (runtime_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}