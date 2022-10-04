#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main()
{
     setlocale(LC_ALL, "Rus");

     //------------------------Task 1------------------------//
     /*float Radius;
     cout << "Enter Rarius: ";
     cin>> Radius;
     float Length = 2 * Radius * M_PI;
     float Area = pow(Radius, 2) * M_PI;
     float Volume = (pow(Radius,3) * M_PI) * 4.0 / 3.0;
     cout <<"Length is: "<< Length << endl;
     cout <<"Area is: " << Area << endl;
     cout <<"Volume is: " << Volume <<endl;*/

     //------------------------Task 2------------------------//
     float First_Number;
     float Second_Number;
     cout << "Enter First Number: ";
     cin >> First_Number;

     cout << endl
          << "Enter Second Number: ";
     cin >> Second_Number;

     float Arithmetic_Mean = (First_Number + Second_Number) / 2;
     float Geometric_Mean = pow(First_Number + Second_Number, 0.5);
     cout << endl
          << "Arithmetic mean :" << Arithmetic_Mean << endl;
     cout << "Geometric mean: " << Geometric_Mean << endl;
}
