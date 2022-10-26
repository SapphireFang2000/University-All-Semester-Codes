#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return ((x * x * x) - x - 3);
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

int match_upto(double number, int match)
{
    int power_number = pow(10, match);
    number *= power_number;
    int upto_match = number;
    upto_match %= power_number;
    return upto_match;
}

int main()
{
    // take_input();
    double x0 = 1;
    double x1 = 3;
    double e = .000000000000001;
    cout << fixed << setprecision(4);

    double x2;

    cout << "**********************************************************************" << endl;
    cout << "iteration" << setw(5) << "" << setw(7) << "x0"<< "" << setw(17) << "x1"<< "" << setw(17) << "x2"<< "" << setw(17) << "f(x0)" << setw(15) << "f(x1)" << setw(15) << "f(x2)" << endl;
    cout << "**********************************************************************" << endl;

    int i = 1;
    double old_x, new_x;

    do
    {

        x2 = x1 - (f(x1) * ((x1 - x0) / (f(x1) - f(x0))));

        cout << i << setw(12) << "" << setw(10) << x0 << "" << setw(17) << x1 << "" << setw(17) << x2 << "" << setw(17) << f(x0) << setw(15) << f(x1) << setw(15) << f(x2) << endl;

        x0 = x1;
        x1 = x2;
        i++;

    } while (fabs(f(x1)) > e);
}
double horners(double x)
{
    int n = 3;
    int j = n;
    int a[n];
    double b[n];

    while (j >= 0)
    {
        b[j] = a[j];
        b[j - 1] = a[j - 1] + (b[j] * x);
        j--;
    }
}