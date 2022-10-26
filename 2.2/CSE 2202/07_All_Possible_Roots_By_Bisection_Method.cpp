#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return (((x * x * x) - (7 * x * x) + (15 * x) - 9));
}
int main()
{
    float a = 0;
    float b = 5;
    float ds = .5;
    float x1 = a;
    float x2 = x1 + ds;
    float error = .00001;

    while (x2 < b)
    {
        x1 = a;
        x2 = x1 + ds;
        if (f(x1) * f(x2) > 0)
        {
            cout << "Wrong guess" << endl;
        }
        else

        {
            float xr;
            float err;
            do
            {
                xr = (x1 + x2) / 2.0;

                if ((f(x1) * f(xr)) < 0)
                {
                    x2 = xr;
                }
                else
                {
                    x1 = xr;
                }
                err = fabs((x2 - x1) / x2);

            } while (fabs((x2 - x1) / x2) >= error);

            cout << "The root is " << xr << endl;
            if (x2 > b)
            {
                break;
            }
        }
        a = x2;
    }
}