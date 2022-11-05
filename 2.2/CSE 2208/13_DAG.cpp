#include<bits/stdc++.h>
#define NODE 6
#define inf INT_MAX

using namespace std;

int cost[NODE][NODE] =
{
        {0,   5,    3,    inf,    inf, inf},
        {inf,   0,    2,     6,      inf, inf},
        {inf,     inf,    0,    7,      4, 8},
        {inf,    inf,    inf,     0,    -1, 1},
        {inf,    inf,    inf,      inf,     0, -2},
        {inf,    inf,    inf,      inf,     inf, 0}
};

void topo(int u, bool visited[], stack<int>&stk)
{
    visited[u] = true;
    for(int v = 0; v<NODE; v++)
    {
        if(cost[u][v])
        {
            if(!visited[v])
                topo(v, visited, stk);
        }
    }

    stk.push(u);
}

int main()
{
    int start;

    cout<<"Enter Starting Node Number: ";
    cin>>start;
    start = start-1;

    cout << "Shortest Path From Source: "<<start<<endl;
    cout<<"is"<<endl;

    stack<int> stk;
    int dist[NODE];

    bool visit[NODE];
    for(int i = 0; i<NODE; i++)
    {
        visit[i] = false;
    }

    for(int i = 0; i<NODE; i++)
    {
        if(!visit[i])
        {
            topo(i, visit, stk);
        }
    }

    for(int i = 0; i<NODE; i++)
    {
        dist[i] = inf;
    }

    dist[start] = 0;

    while(!stk.empty())
    {
        int nextVert = stk.top();

        stk.pop();

        if(dist[nextVert] != inf)
        {
            for(int v = 0; v<NODE; v++)
            {
                if(cost[nextVert][v] && cost[nextVert][v] != inf)
                {
                    if(dist[v] > dist[nextVert] +cost[nextVert][v])
                    {
                        dist[v] = dist[nextVert] + cost[nextVert][v];
                    }
                }
            }
        }
    }

    for(int i = 0; i<NODE; i++)
    {
        if(dist[i] == inf) 
        {
            cout << "infinity ";
        }
        else
        {
            cout << dist[i]<<" ";
        }
    }
}
