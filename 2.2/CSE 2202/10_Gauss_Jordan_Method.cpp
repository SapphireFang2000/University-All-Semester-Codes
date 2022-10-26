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
int gauss_jordan(int n)
{

    for (int i = 1; i <= n; i++)
    {
        if (co_eff[i][i] == 0.0)
        {
            cout << "Error!" << endl;
            return -1;
        }
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                factor = co_eff[j][i] / co_eff[i][i];
                for (int k = 1; k <= n + 1; k++)
                {
                    co_eff[j][k] = co_eff[j][k] - factor * co_eff[i][k];
                }
            }
        }
    }
    return 1;
}
void solution_print(int n)
{

    for (int i = 1; i <= n; i++)
    {
        res[i] = co_eff[i][n + 1] / co_eff[i][i];
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
    // cout << "Enter the order of the matrix: ";
    cin >> n;
    take_input(n);
    int ret = gauss_jordan(n);
    if (ret == 1)
    {
        solution_print(n);
    }
    return 0;
}
/*
KINDLY PASTE THIS INTO THE CONSOLE
3
3 -2 3 -1
-3 9 1 2
2 -1 -7 3

*/