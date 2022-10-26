#include <bits/stdc++.h>
using namespace std;

void horners(int *arr, int n, double x)
{
    int j = n;
    double b[n];

    b[j] = arr[j];
    while (j > 0)
    {
        b[j - 1] = arr[j - 1] + (b[j] * x);
        j--;
    }
    cout << b[0];
}

int main()
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

    horners(x, n, 1);
}


