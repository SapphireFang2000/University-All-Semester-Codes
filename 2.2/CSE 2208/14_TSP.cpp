#include<bits/stdc++.h>

using namespace std;

int N = 5;

struct vertex
{
    int no;
    pair <int, int> path;
    int cost;
    vector<bool> visit;
    vector<int> nodes;

    vector<vector<int> > r_matrix;

    vertex()
    {
        ;
    }

    vertex(int num, int p, vector<vector<int>> matrix, vector<bool> v)
    {
        no = num;
        cost = 0;
        path.first = p;
        path.second = num;

        visit = v;
        r_matrix = matrix;


        visit[num] = true;
    }

    void vector_copy(vector<int> &v)
    {
        for(int i = 0; i < v.size(); i++)
        {
            nodes.push_back(v[i]);
        }
    }

};

int cost_n_reduce(vector<vector<int> > &matrix)
{
    //reduce row
    int cost = 0;
    for(int i = 0; i < N; i++)
    {
        int small = INT_MAX;
        for(int j = 0; j < N; j++)
        {
            if(matrix[i][j] < small)
                small = matrix[i][j];
        }
        for(int k = 0; k < N; k++)
        {
            if(matrix[i][k] != INT_MAX)
                matrix[i][k] = matrix[i][k] - small;
        }
        if(small != INT_MAX)
            cost += small;
    }

    //reduce col
    for(int i = 0; i < N; i++)
    {
        int small = INT_MAX;
        for(int j = 0; j < N; j++)
        {
            if(matrix[j][i] < small)
                small = matrix[j][i];
        }
        for(int k = 0; k < N; k++)
        {
            if(matrix[k][i] != INT_MAX )
                matrix[k][i] = matrix[k][i] - small;
        }
        if(small != INT_MAX)
            cost += small;
    }
    return cost;
}

void pop_node(vector<vertex> &v)
{
    int cost = INT_MAX;
    int temp;

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].cost < cost)
        {
            cost = v[i].cost;
            temp = i;
        }
    }

    swap(v[temp], v[v.size() - 1]);
}

void matrix_inf(vector<vector<int> > &matrix, int row, int col, vector<bool> &v)
{
    for(int i = 0; i < N; i++)
    {
        matrix[row][i] = INT_MAX;
        matrix[i][col] = INT_MAX;
    }
    for(int i = 0; i < N; i++)
    {
        if(v[i] == true)
        {
            matrix[col][i] = INT_MAX;
        }
    }
}

void path(vector<int> &v, int node)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] + 1 << "->";
    cout << node + 1;
}

vertex tsp(vector<vector<int> > &matrix, int root)
{
    vector<bool> b(N, false);
    vertex r = vertex(root, NULL, matrix, b);
    //obj matrix define
    r.cost = cost_n_reduce(r.r_matrix);

    vector <vertex> temp;
    temp.push_back(r);

    while(!temp.empty())
    {
        pop_node(temp);
        vertex m = temp[temp.size() - 1];

        cout << "Path: ";
        path(m.nodes, m.no);
        cout << endl;

        temp.pop_back();
        m.nodes.push_back(m.no);

        for(int i = 0; i < N; i++)
        {
            if(m.r_matrix[m.no][i] != INT_MAX)
            {
                vertex child = vertex(i, m.no, m.r_matrix, m.visit);
                child.vector_copy(m.nodes);

                matrix_inf(child.r_matrix, m.no, child.no, child.visit);

                child.cost = m.cost + m.r_matrix[m.no][i] + cost_n_reduce(child.r_matrix);

                cout << "Node: " << child.no + 1 << " ";
                cout << "Cost: " << child.cost << endl;

                for(int k = 0; k < N; k++)
                {
                    for(int j = 0; j < N; j++)
                    {
                        if(child.r_matrix[k][j] == INT_MAX)
                            cout << "x" <<"\t";

                        else
                            cout << child.r_matrix[k][j] << "\t";
                    }
                    cout << endl;
                }
                temp.push_back(child);
            }
            cout << endl;
        }

        int true_count = 0;
        for(int i = 0; i < N; i++)
        {
            if (m.visit[i] == true)
                true_count++;
        }
        if(true_count == N)
        {
            m.nodes.push_back(m.no);
            return m;
        }

    }
}

int main()
{
    int e, r;

    vector<vector<int>> adj_mat =
    {
        {INT_MAX, 20, 30, 10, 11},
        {15, INT_MAX, 16, 4, 2},
        {3, 5,  INT_MAX, 2, 4},
        {19, 6, 18, INT_MAX, 3},
        {16, 4, 7, 16, INT_MAX}
    };

    cout << "Enter starting node: ";
    cin >> r;

    vertex x = tsp(adj_mat, r - 1);

    cout << endl;
    for(int i = 0; i < N; i++)
        cout << x.nodes[i] + 1 << " -> ";

    cout << "1" << endl;
    cout << "Total cost: " << x.cost;

    return 0;
}
