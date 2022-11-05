#include<bits/stdc++.h>

using namespace std;

void initialize_single_source(int d[], int pi[], int v, int s)
{
    for(int i = 1; i <= v; i++)
    {
        d[i] = INT_MAX;
        pi[i] = NULL;
    }
    d[s] = 0;
}

bool relax(int d[], int pi[], int u, int v, int w)
{
    if(d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        pi[v] = u;
        return true;
    }
    return false;
}

void path(int pi[],int s, int des)
{
    int cost = 0;
    stack<int>path;
    int temp = des;
    while(pi[temp] != NULL)
    {
        path.push(temp);
        temp = pi[temp];
    }

    cout << s;
    while(!path.empty())
    {
        int x = path.top();
        path.pop();
        cout << "->" << x ;
    }

}

void bellman(vector<pair<int, int>> g[], int s, int n)
{
    int pi[n+1];
    int d[n+1];
    bool visit[n+1];
    int ct[n+1] = {0};
    int u, v, w;

    initialize_single_source(d, pi, n, s);

    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 0; k < g[j].size(); k++)
            {
                u = j;
                v = g[j][k].first;
                w = g[j][k].second;

                if(relax(d, pi, u, v, w))
                {
                    ct[v] += 1;
                }
            }
        }
        cout << "Iteration: " << i;
        for(int l = 1; l <= n; l++)
        {
            cout << "Cost: " << d[l] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    cout << "number of updates done to nodes: ";

    for(int i = 1; i <= n; i++)
    {
        cout << ct[i] << "\t";
    }

    cout << endl;
    cout << "path";
    for(int i = 1; i <= n; i++)
    {
        cout << i << ".\t";
        path(pi, s, i);

        cout << "\tCost= " << d[i];

        cout << endl;
    }
}

int main()
{
    int n, e, s;

    cout << "Enter Node Number: ";
    cin >> n;
    cout << "Enter Edge Number: ";
    cin >> e;

    vector <pair<int, int> > adj[n + 1];

    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(make_pair(b, c));
    }

    cout << "Enter starting node: ";
    cin >> s;

    bellman(adj, s, n);
}
