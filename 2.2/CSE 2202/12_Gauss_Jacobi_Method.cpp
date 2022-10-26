#include <bits/stdc++.h>
using namespace std;

double co_eff[100][100], res[100], total, temp[100], error, permit_error = 0.00001, temp_error;

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

    for (int i = 1; i <= n; i++)
        res[i] = 0;
}

void jacobi(int n)
{
    do
    {
        temp_error = 0;
        for (int i = 1; i <= n; i++)
        {
            total = 0;
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    total += co_eff[i][j] * res[j];
                }
            }
            temp[i] = (co_eff[i][n + 1] - total) / co_eff[i][i];
            error = fabs(res[i] - temp[i]);
            if (error > temp_error)
            {
                temp_error = error;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            res[i] = temp[i];
        }
    } while (temp_error >= permit_error);
}
void solution_print(int n)
{
   
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
    jacobi(n);
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