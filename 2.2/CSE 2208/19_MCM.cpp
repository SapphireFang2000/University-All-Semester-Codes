#include<bits/stdc++.h>

using namespace std;

void POP(vector<vector<int>> &s, int i, int j)
{
    if(i == j)
        cout << "A" << i << i;

    else
    {
        cout << "(";
        POP(s, i, s[i][j]);
        cout << "*";
        POP(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void MCM(vector<int> p)
{
    int n = p.size() - 1;
    vector<vector<int>> m(n + 1, vector<int> (n + 1));
    vector<vector<int>> s(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++)
        {
            m[i][i] = 0;
        }

    for(int l = 2; l <= n; l++)
    {
        for(int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "A1" << n << " = ";
    POP(s, 1, n);
}

int main()
{
    int x;
    cout << "Enter length of chain: ";
    cin >> x;
    vector<int> p(x);
    for(int i = 0; i < x; i++)
    {
        cin >> p[i];
    }

    MCM(p);
}
