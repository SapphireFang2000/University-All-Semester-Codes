//Write a Code to Implement Stack Using Linked List

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node* next;

};
node* head = NULL;

int isEmpty()
{
    if(head==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void PUSH(int x)
{
    node *temp = new node();

    if(temp == NULL)
    {
        cout << "Stack Overflow." << endl;
        exit(1);
    }

    temp->val=x;
    temp->next=head;
    head=temp;
}

int POP()
{
    node *curr_node=head;

    if(isEmpty())
    {
        cout << "Stack Underflow." << endl;
        exit(1);
    }

    int data = curr_node->val;
    head=head->next;
    free(curr_node);
    curr_node = NULL;
    return data;
}

void PRINT()
{
    node *curr_node=head;

    if(isEmpty())
    {
        cout << "Stack Underflow." << endl;
        exit(1);
    }

    cout << "The stack elements are: ";

    while(curr_node)
    {
        cout << curr_node->val;
        curr_node = curr_node->next;
    }
    cout << endl;
}

int main()
{
    int choice, value;

    cout << "----------Write a code to implement Stack using linked list----------" << endl;

    while(true)
    {
        cout << "\n1. Push\n2. Pop\n3. Print all the elements of the stack\n4. Exit\n";
        cout << "Please enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter the element to be pushed: ";
                cin >> value;
                PUSH(value);
                break;

            case 2:
                value = POP();
                cout << "Deleted element is " << value << endl;
                break;

            case 3:
                PRINT();
                break;

            case 4:
                exit(1);

            default:
                cout << "Wrong Choice" << endl;
        }
    }

    return 0;
}
