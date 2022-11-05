#include<bits/stdc++.h>

using namespace std;

priority_queue<pair<int , pair<int, int> > > q;

int s[100];

sort_edges(vector<pair<int, int> > v[], int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            q.push(make_pair(-v[i][j].second, make_pair(i, v[i][j].first)));
        }
    }
}

void makeset(int v)
{
    s[v] = v;
}

int findset(int x)
{
    return s[x];
}

void uni(int u, int v, int n)
{
    int temp = s[v];
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == temp)
            s[i] = s[u];
    }
}

void kruskal(vector<pair<int, int> > v[], int n, int e)
{
    vector<pair<int, int> > T;
    for(int i = 1; i <= n; i++)
        makeset(i);

    sort_edges(v, n);

    int cost = 0;

    while(!q.empty())
    {
        pair<int, int> p;
        int w = -q.top().first;

        p = q.top().second;
        q.pop();

        int u = p.first;
        int v = p.second;

        if(findset(u) != findset(v))
        {
            T.push_back(make_pair(u, v));
            uni(u, v, n);

            cost += w;
        }
    }

    cout << "{ ";
    for(int i = 0; i < T.size(); i++)
    {
        cout <<"(" << T[i].first << ", " << T[i].second << ")";
    }
    cout << " }" << endl;

    cout << "cost: " << cost;



}

int main()
{
    int N;
    int e, r;

    cout << "Enter Node Number: ";
    cin >> N;
    cout << "Enter Edge Number: ";
    cin >> e;

    vector <pair<int, int> > v[N + 1];

    cout << "Source : Destination : Weight" << endl;
    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back(make_pair(b, c));
    }

    kruskal(v, N, e);
}
