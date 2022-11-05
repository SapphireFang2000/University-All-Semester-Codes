#include<bits/stdc++.h>

using namespace std;

void knapsack(vector<vector<int>> &V, vector<pair<int, int>> b, int W, int n)
{
    for(int i = 0; i <= W; i++)
    {
        V[0][i] = 0;
    }

    for(int i = 0; i <= n; i++)
    {
        V[i][0] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int w = 1; w <= W; w++)
        {
            if(b[i].first <= w)
            {
                if(b[i].second + V[i - 1][w - b[i].first] > V[i - 1][w])
                {
                    V[i][w] = b[i].second + V[i - 1][w - b[i].first];
                }

                else
                {
                    V[i][w] = V[i - 1][w];
                }
            }
            else
            {
                V[i][w] = V[i - 1][w];
            }
        }
    }
}

void find_item(vector<vector<int>> &V,vector<pair<int, int>> b, int w, int n)
{
    vector<bool> item(n + 1);

    int i= n, j = w;
    
    while(i != 0)
    {

        if(V[i][j] != V[i-1][j])
        {
            item[i] = true;
            j = j - b[i].first;
            i = i - 1;
        }
        else
        {
            i = i - 1;
        }
    }

    for(int i = 1; i <= n ; i++)
    {
        cout << item[i] << " ";
    }
}


int main()
{
    int n;
    int a, b, w;

    cout << "Enter total item number: ";
    cin >> n;
    cout << "Enter weight of knapsack: ";
    cin >> w;

    vector<pair<int , int> > v(n + 1);

    vector<vector<int> > V(n + 1, vector<int> (w + 1));

    cout << "No Weight Price" << endl;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        v[i] = {a, b};
    }

    knapsack(V, v, w, n);

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            cout << V[i][j] << "\t";
        }
        cout << endl;
    }

    find_item(V, v, w, n);
}
