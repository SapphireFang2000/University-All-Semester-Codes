#include <bits/stdc++.h>
using namespace std;

vector<int> g_node[10];

void DFS(int start, int node)
{
    bool visited[node] = {false};
    stack<int> s;
    visited[start] = true;
    s.push(start);
    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        cout << v << endl;
        for (int i = 0; i < g_node[v].size(); i++)
        {
            if (visited[g_node[v][i]] == false)
            {
                visited[g_node[v][i]] = true;
                s.push(g_node[v][i]);
            }
        }
    }
}

int main()
{
    int node, edge, sp, ep;
    printf("Enter number of nodes : ");
    scanf("%d", &node);
    printf("Enter number of edges : ");
    scanf("%d", &edge);
    for (int i = 0; i < edge; i++)
    {
        cout << "Enter edge " << i + 1 << " start point : ";
        cin >> sp;
        cout << "Enter edge " << i + 1 << " end point : ";
        cin >> ep;
        g_node[sp].push_back(ep);
    }

    for (int i = 1; i <= node; i++)
    {
        cout << i << " ->";
        for (int j = 0; j < g_node[i].size(); j++)
        {
            cout << " " << g_node[i][j];
        }
        cout << endl;
    }

    int sn;
    cout << "Enter starting node : ";
    cin >> sn;

    DFS(sn, node);

    return 0;
}
