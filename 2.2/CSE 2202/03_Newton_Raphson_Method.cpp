#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return ((x * x * x) - x - 1);
}
double df(double x)
{
    return (3 * (x * x)) - 1;
}

void take_input()
{
    int n;
    cout << "Enter the total no of power" << endl;
    cin >> n;
    int i = 0;
    int x[n];

    while (i <= n)
    {
        cout << "x^" << i << "::";
        cin >> x[i];
        cout << endl;
        i++;
    }
    i--;

    cout << "The polynomial is" << endl;

    while (i >= 0)
    {

        cout << x[i] << "x^" << i << " + ";

        i--;
    }
    cout << endl;

    cout << "Enter the initial guess" << endl;
    int initial_guess;
    cin >> initial_guess;
    cout << endl;
}



int main()
{
    // take_input();
    double x1 = 3;
    double e = .000000000000001;
    cout << fixed << setprecision(4);

    double x2;

    cout << "**********************************************************************" << endl;
    cout << " Iteration\t x1\t\t F(x1)\t\tF'(x1)" << endl;
    cout << "**********************************************************************" << endl;

    int i = 1;
    double old_x, new_x;

    do
    {

        x2 = x1 - (f(x1) / df(x1));

        if (i < 10)
            cout << i << setw(12) << "" << setw(10) << x1 << "" << setw(17) << f(x1) << setw(15) << df(x1) << endl;
        else
            cout << i << setw(11) << "" << setw(10) << x1 << "" << setw(17) << f(x1) << setw(15) << df(x1) << endl;

        x1 = x2;
        i++;

    } while (fabs(f(x1)) > e);
}

