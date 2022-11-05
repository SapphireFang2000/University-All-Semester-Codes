#include<bits/stdc++.h>
using namespace std;

vector<int> x;

bool Place(int k, int i)
{
    for(int j = 1; j < k; j++)
    {
        if(x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return false;
        }
    }

    return true;
}

void NQueens(int k, int n)
{
    x.resize(n + 1);

    for(int i = 1; i <= n; i++)
    {
        if(Place(k, i))
        {
            x[k] = i;
            if(k == n)
            {
                for(int j = 1; j <= n; j++)
                {
                    cout << x[j] << " ";
                }  
                cout << endl;
            }
            else
            {
                NQueens(k + 1, n);
            }   
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of Queens: ";
    cin >> n;

    NQueens(1, n);
}
