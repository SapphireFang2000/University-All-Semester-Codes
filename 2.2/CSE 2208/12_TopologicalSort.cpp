#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;

void graph_input(vector<pr> adj[], int node, int edge)
{
    int sp, ep, we;
    for(int i = 0; i < edge; i++)
    {
        cout << "Enter edge " << i + 1 << " start point : ";
        cin >> sp;
        cout << "Enter edge " << i + 1 << " end point: ";
        cin >> ep;
        cout << "Enter edge " << i + 1 << " weight: ";
        cin >> we;
        adj[sp].push_back(pr(we, ep));
    }
}

void graph_output(vector<pr> adj[], int node, int edge)
{
    for (int i = 1; i <= node; i++)
    {
        cout << i;
        for(int j = 0; j < adj[i].size(); j++)
        {
            cout << " -> " << adj[i][j].second << " " << adj[i][j].first;
        }
        cout << endl;
    }
}

void depth(vector <pr> g_node[], int i, bool visited[], stack<int> &s)
{
    visited[i] = true;

    for (int j = 0; j < g_node[i].size(); j++)
    {
        if (visited[g_node[i][j].second] == false)
        {
            depth(g_node, g_node[i][j].second, visited, s);
        }
    }

    s.push(i);
}

vector<int> topologicalSort(vector <pr> g_node[], int node)
{
    stack<int> s;
    vector<int> order;
    bool visited[node] = { false };

    for (int i = 1; i <= node; i++)
    {
        if (visited[i] == false)
        {
            depth(g_node, i, visited, s);
        }
    }

    while (s.empty() == false)
    {
        order.push_back(s.top());
        s.pop();
    }

    return order;
}

int main()
{
    int n, e;
    cout << "Enter number of nodes : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> e;

    vector<pr> adj[n + 1];

    graph_input(adj, n, e);
    graph_output(adj, n, e);

    vector<int> sorted_order = topologicalSort(adj, n);

    for (int i = 0; i < n; i++)
    {
        cout << sorted_order[i] << " ";
    }
    cout << endl;

    return 0;
}
