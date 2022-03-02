//Single Linked List

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node* next;

};
node* head = NULL;

//Insert a value in first position.
void INSERT_F(int x)
{
    node *temp = new node();
    temp->val = x;
    temp->next = head;
    head = temp;
}

//Insert a value in nth position.
void INSERT_N(int x, int n)
{
    node *temp = new node();
    temp->val = x;
    temp->next = NULL;
    int c = 0;
    node *curr_node = head;
    if(n == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        while(1)
        {
            c++;
            if(c == n-1)
            {
                temp->next = curr_node->next;
                curr_node->next = temp;
                break;
            }
            curr_node = curr_node->next;
        }
    }
}

//Insert a value in last position.
void INSERT_L(int x)
{
    node *curr_node = head, *temp;
    temp = new node();
    temp->val = x;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        while(1)
        {
            if(curr_node->next==NULL)
            {
                curr_node->next=temp;
                break;
            }
            curr_node=curr_node->next;
        }
    }
}

//Delete a value in first position.
void DELETE_F()
{
    node *curr_node=head;
    head=head->next;
    free(curr_node);
}

//Delete a value in nth position.
void DELETE_N(int n)
{
    int c=0;
    if(n==1)
    {
        node *temp;
        temp=head;
        head=head->next;
        free(temp);
    }
    else
    {
        node *curr_node=head;
        while(1)
        {
            c++;
            node *temp;
            if(c==n-1)
            {
                temp=curr_node->next;
                curr_node->next=curr_node->next->next;
                free(temp);
                break;
            }
            curr_node=curr_node->next;
        }
    }
}

//Insert a value in last position.
void DELETE_L()
{
    node *curr_node=head;
    while(1)
    {
        if(curr_node->next->next==NULL)
        {
            curr_node->next=NULL;
            free(curr_node->next);
            break;
        }
        curr_node=curr_node->next;
    }
}

//Search a value.
int SEARCH(int x)
{
    int c=0, flag=0;
    node *curr_node = head;
    while(curr_node != NULL)
    {
        c++;

        if(curr_node->val == x)
        {
            flag=1;
            return c;
        }
        
        curr_node = curr_node->next;
    }

    if(flag == 0)
    {
        return -1;
    }

    cout << endl;
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


int main()
{
    int x,n;

    while(true)
    {
        cout << "1. Insert First\n2. Insert N\n3. Insert Last\n4. Delete First\n5. Delete N\n6. Delete Last\n7. Print\n8. Search\n9. Exit\n";
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
                return 0;
                
                break;

            default:
                continue;
        }
    }

    return 0;
}
