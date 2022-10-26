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
    x = (a + b) / 2.0;
    while (fabs(f(x)) > error)
    {

        x = (a + b) / 2.0;

        if (f(x) * f(a) < 0)
        {
            b = x;
        }
        else if (f(x) * f(b) < 0)
        {
            a = x;
        }
        x = (a + b) / 2.0;
    }

    cout << "The root is " << x << endl;
}