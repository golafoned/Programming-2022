using namespace std;
#include <iostream>
#include <string>
#include <math.h>
struct Point
{
    double x, y;
};
class Line
{
private:
    double a, b, c;

public:
    Line() : a(0), b(0), c(0){};
    Line(const Line &p) : a(p.a), b(p.b), c(p.c) {}
    friend istream &operator>>(istream &is, Line &line)
    {
        is >> line.a >> line.b >> line.c;
        return is;
    }
    friend ostream &operator<<(ostream &os, Line &line)
    {
        os << line.a << 'x' << '+' << line.b << 'y' << '+' << line.c << '=' << '0';
        return os;
    }
    Point getIntercetion(Line &line)
    {
        double bottom = a * line.b - line.a * b;
        double x = (b * line.c - line.b * c) / bottom;
        double y = (c * line.a - line.a) / bottom;
        Point p;
        p.x = x;
        p.y = y;
        return p;
    }
    bool isInterception(Line &l2)
    {
        double bottom = a * l2.b - l2.a * b;
        if (bottom == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    double getAngle(Line &line2)
    {
        double angle = (line2.a * a + line2.b * b) / (sqrt(line2.a * line2.a + line2.b * line2.b) * sqrt(a * a + b * b));
        return angle;
    }
    bool isonaline(Point &p)
    {
        if (a * p.x + b * p.y + c == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    const int n = 10;
    Line line;
    Line *array = new Line[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i].isInterception(array[j]))
            {
                cout << "line " << array[i] << "intercepts " << array[j] << endl;
                cout << "point of interception is " << array[i].getIntercetion(array[j]).x << "," << array[j].getIntercetion(array[j]).y;
            }
        }
    }
    return 0;
}