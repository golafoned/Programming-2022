#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Visit
{
    int day;
    int hour;
    int visitors;
};

int main()
{
    ifstream inputFile("input.txt");
    map<int, vector<Visit>> visitsByDay;

    int day, hour, visitors;
    while (inputFile >> day >> hour >> visitors)
    {
        visitsByDay[day].push_back({day, hour, visitors});
    }
    inputFile.close();

    ofstream outputFile1("file1.txt");

    for (const auto &entry : visitsByDay)
    {
        const vector<Visit> &visits = entry.second;

        int maxVisitors = 0;
        for (const Visit &visit : visits)
        {
            if (visit.visitors > maxVisitors)
            {
                maxVisitors = visit.visitors;
            }
        }

        outputFile1 << "Day " << entry.first << ": ";
        for (const Visit &visit : visits)
        {
            if (visit.visitors == maxVisitors)
            {
                outputFile1 << visit.hour << " ";
            }
        }
        outputFile1 << "\n";
    }
    outputFile1.close();

    ofstream outputFile2("file2.txt");

    vector<pair<int, int>> daysByTotalVisitors;
    for (const auto &entry : visitsByDay)
    {
        const vector<Visit> &visits = entry.second;

        int totalVisitors = 0;
        for (const Visit &visit : visits)
        {
            totalVisitors += visit.visitors;
        }

        daysByTotalVisitors.push_back({entry.first, totalVisitors});
    }

    sort(daysByTotalVisitors.begin(), daysByTotalVisitors.end(), [](const auto &a, const auto &b)
         { return a.second > b.second; });

    for (const auto &entry : daysByTotalVisitors)
    {
        outputFile2 << "Day " << entry.first << ": " << entry.second << " visitors\n";
    }
    outputFile2.close();

    cout << "Success.\n";

    return 0;
}
