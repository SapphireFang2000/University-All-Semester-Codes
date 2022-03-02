/*        1
      4       5
          2
          3

Traverse the tree using DFS.
*/

#include <bits/stdc++.h>
using namespace std;

int graph[200][200];
int status[200];

struct node
{
    int val;
    node* next;
};
node* head;

void push(int x)
{
    node *temp = new node();

    temp->val=x;
    temp->next=head;
    head=temp;
}

int pop()
{
    node *curr_node=head;

    int data = curr_node->val;
    head=head->next;
    free(curr_node);
    curr_node = NULL;
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

    printf("\n");

    for(int i=1; i<=E; i++)
    {
        scanf("%d %d", &so, &des);
        graph[so][des] = 1;
    }

}

void printAM(int N) //Printing Adjacent Matrix.
{
    printf("\n");
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    printf("\n");
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
    for(int i=1; i<=n; i++)
    {
        if(graph[nodeN][i]==1 && status[i] == 1)
        {
            push(i);
            status[i] = 2;
        }
    }

}

void dfs(int source, int n)
{
    //step 1
    initStatus(n);

    //step 2
    push(source);
    status[source] = 2;

    //step 3
    while(isEmpty())
    {
        //step 4
        int N;  //do necessary things
        N = pop();
        status[N] = 3;
        printf("%d ",N);

        //step 5
        addNeighbors(N, n);

    }
}

int main()
{
    int n,e, source;
    printf("Enter Number of Node: ");
    scanf("%d",&n);

    printf("Enter Number of Edge: ");
    scanf("%d", &e);

    printf("Enter Source: ");
    scanf("%d", &source);

    inputGraph(n,e);
    printAM(n);
    dfs(source,n);

    return 0;
}

/*
    Sample Input:
                Enter Number of Node: 5
                Enter Number of Edge: 5
                Enter Source: 1
                1 4
                1 5
                4 2
                5 2
                2 3

    Sample Output:
                  0 0 0 1 1
                  0 0 1 0 0
                  0 0 0 0 0
                  0 1 0 0 0
                  0 1 0 0 0

                  1 4 5 2 3
*/