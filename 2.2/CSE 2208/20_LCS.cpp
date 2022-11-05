#include<bits/stdc++.h>

using namespace std;

void Print_LCS(vector<vector<int>> &b, string x, int i, int j)
{
    if(i == 0 || j == 0)
    {
        return;
    }
        
    if(b[i][j] == 1)
    {
        Print_LCS(b, x, i - 1, j - 1);
        cout << x[i - 1];
    }
    else if(b[i][j] == 2)
    {
        Print_LCS(b, x, i - 1, j);
    }
    else
    {
        Print_LCS(b, x, i, j - 1);
    }
}

void LCS_Length(string x, string y)
{
    int m = x.size();
    int n = y.size();

    vector<vector<int> > c(m + 1, vector<int> (n + 1));
    vector<vector<int> > b(m + 1, vector<int> (n + 1, 0));

    for(int i = 1; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for(int j = 1; j <= n; j++)
    {
        c[0][j] = 0;
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else if(c[i - 1][j] >= c[i][j -1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
    }

    cout << "LCS: ";
    Print_LCS(b, x, m, n);
    cout << endl;
    cout << "Length of LCS: " << c[m][n];
}

int main()
{
    string x;
    string y;

    cout << "Enter 1st string: ";
    cin >> x;

    cout << "Enter 2nd string: ";
    cin >> y;

    LCS_Length(x, y);
}
