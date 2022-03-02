//Write a Code to Implement Queue Using Linked List

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
    if(head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ENQUEUE(int x)
{
    node *temp = new node();

    if(temp == NULL)
    {
        cout << "Stack Overflow." << endl;
        exit(1);
    }

    temp->val = x;
    temp->next = head;
    head = temp;
}

int DEQUEUE()
{
    int data;

    if(isEmpty())
    {
        cout << "Stack Underflow." << endl;
        exit(1);
    }

    else if(head->next == NULL)
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

void PRINT()
{
    node *curr_node = head;

    if(isEmpty())
    {
        cout << "Stack Underflow." << endl;
        exit(1);
    }

    cout << "The stack elements are: ";

    while(curr_node)
    {
        cout << curr_node->val;
        curr_node=curr_node->next;
    }

    cout << endl;
}

int main()
{
    int choice, value;

    cout << "----------Write a code to implement Stack using linked list----------" << endl;

    while(true)
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Print all the elements of the stack\n4. Exit\n";
        cout << "Please enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter the element to be enqueued: ";
                cin >> value;
                ENQUEUE(value);
                break;

            case 2:
                value = DEQUEUE();
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
