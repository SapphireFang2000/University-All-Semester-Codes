#include<bits/stdc++.h>

using namespace std;

#define Size 100

int qu[Size];
int top = -1;

void Enqueue(int item)
{
    if(top >= Size)
    {
        cout << "Queue OverFlow" << endl;
    }
    else
    {
        top++;
        qu[top] = item;
        cout << "The queue is"<< endl;
    }
}

int Dequeue()
{
    if(top < 0)
    {
        printf("Queue Is Empty. \n");
        return -1;
    }
    else
    {
        int pos;
        int big = qu[0];

        for(int i = 1; i <= top; i++)
        {
            if(qu[i] > big)
            {
                big = qu[i];
                pos = i;
            }
        }

        for(int i = pos; i <= top - 1; i++)
        {
            qu[i] = qu[i +1];
        }

        top = top - 1;
        return big;
    }
}

int size()
{
    return top + 1;
}

bool isEmpty()
{

    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{

    int operation, item,queuesize;
    bool queue_info;

    while(1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("4. IsEmpty\n");
        printf("************************************\n");
        printf("Please Enter your operation Number: ");

        scanf("%d", &operation);

        switch(operation)
        {
        case 1 :
            printf("Enter item to enqueue into Queue: ");
            scanf("%d", &item);

            Enqueue(item);
            for(int i=0; i<=top; i++)
            {
                printf("  %d  ",qu[i]);
            }
            break;

        case 2 :

            item = Dequeue();

            if(item != isEmpty())
                printf("ITEM  => %d\n", item);
                 for(int i=0; i<=top; i++)
            {
                printf("  %d  ",qu[i]);
            }
            break;

        case 3 :

            queuesize = size();
            printf("Queue size is  %d  \n",queuesize);
            break;

        case 4 :
            queue_info = isEmpty();
            if(queue_info == true)
            {
                printf("Queue is Empty \n");
            }
            else
            {
                printf("Queue has already %d item",size());
            }
            break;
        }

        printf("\n");
        printf("------------------------END---------------------------\n");
        printf("\n\n");
    }
    return 0;
}
