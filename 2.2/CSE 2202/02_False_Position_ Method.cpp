#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return ((x * x * x) - x - 1);
}
int main()
{
    float a = 1;
    float b = 2;
    float error = .000001;
    float x = 0;

    do
    {

        x = a - ((f(a) * (b - a)) / (f(b) - f(a)));
        if (f(x) * f(a) < 0)
        {
            b = x;
        }
        else if (f(x) * f(b) < 0)
        {
            a = x;
        }
       
    } while (fabs(f(x)) >= error);

    cout << "The root is " << x << endl;
}