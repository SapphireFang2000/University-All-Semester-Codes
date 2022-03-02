//Doubly Linked List

#include <bits/stdc++.h>
using namespace std;

struct node
{
    node* prev;
    int val;
    node* next;
};

node* head = NULL,*tail=NULL;

//Insert a value in first position.
void INSERT_F(int x)
{
    node *temp=new node();
    temp->val=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        node *curr_node=head;
        temp->next=curr_node;
        curr_node->prev=temp;
        head=temp;
        while(curr_node->next!=NULL)
        {
            curr_node=curr_node->next;
        }
        tail=curr_node;

    }
}

//Insert a value in nth position.
void INSERT_N(int x, int n)
{
    node *temp=new node();
    temp->val=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        node *curr_node=head;
        int Count=0;
        while(curr_node!=NULL)
        {
            Count++;
            if(Count==n-1)
            {

                temp->prev=curr_node;
                temp->next=curr_node->next;
                curr_node->next->prev=temp;
                curr_node->next=temp;
                curr_node=temp;
                break;
            }
            else
            {
                curr_node=curr_node->next;
            }
        }
    }

}

//Insert a value in last position.
void INSERT_L(int x)
{
    node *temp=new node();
    temp->val=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        node *curr_node=tail;
        curr_node->next=temp;
        temp->prev=curr_node;
        tail=temp;
        while(curr_node->prev!=NULL)
        {
            curr_node=curr_node->prev;
        }
        head=curr_node;
    }

}

//Delete a value in first position.
void DELETE_F()
{
    node *curr_node=head;
    curr_node=curr_node->next;
    curr_node->prev=NULL;
    free(head);
    head=curr_node;

}

//Delete a value in nth position.
void DELETE_N(int n)
{
    node *curr_node=head;
    int i;
    for(i=1; i<n; i++)
    {
        curr_node=curr_node->next;
    }
    curr_node->next->prev=curr_node->prev;
    curr_node->prev->next=curr_node->next;
    curr_node->next=NULL;
    curr_node->prev=NULL;
    free(curr_node);

}

//Delete a value in last position.
void DELETE_L()
{
    node *curr_node=tail;
    curr_node=curr_node->prev;
    curr_node->next=NULL;
    free(tail);
    tail=curr_node;

}

//Search a value.
int SEARCH(int x)
{
    int c=0, flag=0;
    node *curr_node=head;
    while(curr_node!=NULL)
    {
        c++;
        if(curr_node->val==x)
        {
            flag == 1;
            return c;
        }
        curr_node=curr_node->next;
    }

    if(flag == 0)
    {
        return -1;
    }
}

//Print the linked list.
void PRINT()
{
    node *curr_node=head;
    while(1)
    {
        cout << curr_node->val;
        if(curr_node->next==NULL)
        {
            break;
        }
        curr_node=curr_node->next;
    }

    cout << endl << endl;
}

//Print the linked list in reverse.
void PRINT_REV()
{
    node *curr_node=tail;
    while(1)
    {
        cout << curr_node->val;
        if(curr_node->prev==NULL)
        {
            break;
        }
        curr_node=curr_node->prev;
    }
    cout << endl << endl;
}


int main()
{
    int x,n;

    while(true)
    {
        cout << "\n1. Insert First\n2. Insert N\n3. Insert Last\n4. Delete First\n5. Delete N\n6. Delete Last\n7. Print\n8. Search\n9. Print Reverse\n10. Exit\n";
        cout << "Enter Choice: ";

        int ch;

        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "\nEnter value: ";
                cin >> x;

                INSERT_F(x);

                break;

            case 2:
                cout << "\nEnter value: ";
                cin >> x;

                cout << "\nEnter position: ";
                cin >> n;

                INSERT_N(x,n);

                break;

            case 3:
                cout << "\nEnter value: ";
                cin >> x;

                INSERT_L(x);

                break;

            case 4:
                DELETE_F();

                break;

            case 5:
                cout << "\nEnter position: ";
                cin >> n;

                DELETE_N(n);

                break;

            case 6:
                DELETE_L();

                break;

            case 7:
                PRINT();

                break;

            case 8:
                cout << "\nEnter value: ";
                cin >> x;

                if(SEARCH(x) != -1)
                {
                    cout << "Value found at position: " << SEARCH(x) << endl << endl;
                }
                else
                    cout << "Value not found in any index" << endl << endl;
                
                break;

            case 9:
                PRINT_REV();
                break;

            case 10:
                return 0;
                break;

            default:
                continue;
        }
    }

    return 0;
}
