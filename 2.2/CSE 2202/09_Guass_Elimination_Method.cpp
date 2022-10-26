#include <bits/stdc++.h>
using namespace std;

double co_eff[100][100], res[100], factor;


void take_input(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            // cout << "Co-efficient of a " << i << " " << j << endl;
            cin >> co_eff[i][j];
        }
    }
}
void gauss_elimination(int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            factor = co_eff[j][i] / co_eff[i][i];
            for (int k = 1; k <= n + 1; k++)
            {
                co_eff[j][k] = co_eff[j][k] - factor * co_eff[i][k];
            }
        }
    }
}

void solution_print(int n)
{
    res[n] = co_eff[n][n + 1] / co_eff[n][n];
    for (int i = n - 1; i >= 1; i--)
    {
        res[i] = co_eff[i][n + 1];
        for (int j = i + 1; j <= n; j++)
        {
            res[i] = res[i] - co_eff[i][j] * res[j];
        }
        res[i] = res[i] / co_eff[i][i];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "x" << i << " = ";
        cout << res[i] << endl;
    }
}
int main()
{
    int n;
    // cout<<"Enter the order of the matrix: ";
    cin >> n;
    take_input(n);
    gauss_elimination(n);
    solution_print(n);

    return 0;
}

/*
KINDLY PASTE THIS INTO THE CONSOLE
3
3 -2 3 -1
-3 9 1 2
2 -1 -7 3

*/