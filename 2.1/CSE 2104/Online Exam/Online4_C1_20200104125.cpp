#include <bits/stdc++.h>
using namespace std;

int graph[200][200];
int status[200];
int temp = 0;

struct node
{
    int val;
    node* next;
};
node* head;

void enQueue(int x)
{
    node *temp = new node();

    temp->val = x;
    temp->next = head;
    head = temp;
}
int deQueue()
{
    int data;

    if(head->next == NULL)
    {
        data = head->val;
        free(head);
        head = NULL;
    }

    else
    {
        node *curr_node = head;
        node *prev = head;

        while(curr_node->next != NULL)
        {
            prev = curr_node;
            curr_node = curr_node->next;
        }

        prev->next = NULL;
        data = curr_node->val;
        free(curr_node);
        curr_node = NULL;
    }

    return data;
}

bool (isEmpty())
{
    if(head != NULL)
    {
        return 1;
    }
}

void inputGraph(int N, int E)
{
    int so, des;

    cout << endl;

    for(int i=1; i<=E; i++)
    {
        cin >> so >> des;
        graph[so][des] = 1;
    }
}

void printAM(int N) //Printing Adjacent Matrix.
{
    cout << endl;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void initStatus(int N)
{
    for (int i=1; i<=N; i++)
    {
        status[i] = 1;
    }
}

void addNeighbors(int nodeN, int n)
{
    temp++;

    for(int i=1; i<=n; i++)
    {
        if(graph[nodeN][i]==1 && status[i] == 1)
        {
            enQueue(i);
            status[i] = 2;
        }
    }
}

void bfs(int source, int n)
{
    //step 1
    initStatus(n);

    //step 2
    enQueue(source);
    status[source] = 2;

    //step 3
    while(isEmpty())
    {
        //step 4
        int N;  //do necessary things
        N = deQueue();
        status[N] = 3;

        //step 5
        addNeighbors(N, n);
    }
}

int main()
{
    int n,e, source;
    cout << "Enter Number of Node: ";
    cin >> n;

    cout << "Enter Number of Edge: ";
    cin >> e;

    inputGraph(n,e);
    printAM(n);
    for(int i=1; i<=n; i++)
    {
        bfs(i,n);
    }

    if(temp == n*n)
    {
        cout << "Transitive" << endl;
    }

    else
        cout << "Non Transitive" << endl;

    return 0;
}

