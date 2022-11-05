#include<bits/stdc++.h>

using namespace std;

void papsp(vector< vector<int> > pi, int i, int j)
{
    if(i == j)
        cout << i + 1 << " -> ";
    else
    {
        papsp(pi, i, pi[i][j]);
        cout << j + 1 << " -> ";
    }

}


void inti(vector< vector<int> > d, vector< vector<int> > &pi, int n)
{
    for(int k = 0; k < n; k++)
    {

        for(int j = 0; j < n; j++)
        {
            if(d[k][j] == INT_MAX || d[k][j]== 0)
                pi[k][j] = -1;

            else
                pi[k][j] = k;
        }

    }
}

void floyd(vector<vector<int> > w)
{
    int n = w.size();
    vector< vector< vector<int> > > d(n + 1, w);
    vector< vector< vector<int> > > pi(n + 1, w);

    d[0] = w;
    inti(d[0], pi[0], n);

    for(int k = 1; k <= n; k++)
    {
        d[k] = d[k-1];
        pi[k] = pi[k-1];
        for(int i = 0; i < n; i++)
        {
           for(int j = 0; j < n; j++)
           {
               if(d[k-1][i][k - 1] != INT_MAX && d[k-1][k - 1][j] != INT_MAX)
                   if( (d[k-1][i][k - 1] + d[k-1][k - 1][j]) < d[k-1][i][j])
                   {
                       d[k][i][j] = d[k-1][i][k - 1] + d[k-1][k - 1][j];
                       pi[k][i][j] = pi[k-1][k - 1][j];
                   }
           }
        }
        cout << "d["<< k << "]: " << endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(d[k][i][j] == INT_MAX)
                    cout << "x" <<"\t";

                else
                    cout << d[k][i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;

        cout << "pi[" << k << "]: " << endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pi[k][i][j] == -1)
                    cout << "NIL" <<"\t";

                else
                    cout << pi[k][i][j] + 1 << "\t";
            }
            cout << endl;
        }

        cout << endl;
        cout << endl;
        cout << endl;


    }

    for(int i = 0; i < n; i++)
    {
        cout << "all paths from " << i + 1 << ": " << endl;
        for(int j = 0; j < n; j++)
        {

            if(pi[n][i][j] == -1)
                cout << "No path from " << i + 1 << " to " << j + 1 << " exists";
            else
                papsp(pi[n], i, j);

            cout << "\t Cost: " << d[n][i][j];
            cout << endl;
        }

        cout << endl;
    }
}


int main()
{
    int e, r;

    vector<vector<int>> d =
    {
        {0, 3, 8, INT_MAX, -4},
        {INT_MAX, 0,  INT_MAX, 1,  7},
        {INT_MAX,  4,  0,  INT_MAX,  INT_MAX},
        {2, INT_MAX,  -5, 0,  INT_MAX},
        {INT_MAX, INT_MAX,  INT_MAX, 6,  0}
    };

    floyd(d);

}
