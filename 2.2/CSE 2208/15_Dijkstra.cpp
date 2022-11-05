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

void dijkstra(vector<pair<int, int>> g[], int s, int v)
{
    int pi[v+1];
    int d[v+1];
    bool visit[v+1];

    initialize_single_source(d, pi, v, s);

    priority_queue<pair<int, int>> q;

    q.push(make_pair(0, s));

    while(!q.empty())
    {
        pair<int, int> temp;
        temp = q.top();
        q.pop();
        int u = temp.second;

        for(int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].second;
            int w = g[u][i].first;

            if(relax(d, pi, u, v, w))
            {
                q.push(make_pair(-d[v], v));
            }
        }
    }
    for(int i = 1; i < v; i++)
    {
        cout << i << ".\t";

        path(pi, s, i);

        cout << "\t\tCost= " << d[i];
        cout << endl;
    }
}

int main()
{
    int N;
    int e, r;

    cout << "Enter Node Number: ";
    cin >> N;
    cout << "Enter Edge Number: ";
    cin >> e;

    vector <pair<int, int> > adj[N + 1];

    cout << "Source : Destination : Weight" << endl;
    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(make_pair(c, b));
    }

    for(int i = 0; i < N; i++)
    {
        cout << "Source: " << i+1 << endl;
        dijkstra(adj, i + 1, N + 1);
        cout << endl;
    }
}
