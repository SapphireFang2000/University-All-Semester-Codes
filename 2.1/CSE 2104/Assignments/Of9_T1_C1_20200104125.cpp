//Write a Code for Iterative Pre-Order, In-Order, Post-Order and Level-Order Binary Tree Traversal.
//Please see the PDF named Sample Tree Image.

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *root = NULL;

struct Tuples_Stack
{
    Node *p;
    int i;

    Tuples_Stack(Node *n, int x)
    {
        p = n;
        i = x;
    }

    void setI(int x)
    {
        i = x;
    }

    int getPVal()
    {
        return p->data;
    }

    Node* left()
    {
        return p->left;
    }

    Node* right()
    {
        return p->right;
    }
};

struct Tuples_Queue
{
    Node *p;

    Tuples_Queue(Node *n)
    {
        p = n;
    }

    int getPVal()
    {
        return p->data;
    }

    Node* left()
    {
        return p->left;
    }

    Node* right()
    {
        return p->right;
    }
};

void create_tree()
{
    Node *two   = new Node(2);
    Node *seven = new Node(7);
    Node *nine  = new Node(9);
    Node *one   = new Node(1);
    Node *six   = new Node(6);
    Node *five  = new Node(5);
    Node *ten   = new Node(10);
    Node *eight = new Node(8);
    Node *three = new Node(3);
    Node *four  = new Node(4);

    two->left       = seven;
    two->right      = nine;
    seven->left     = one;
    seven->right    = six;
    six->left       = five;
    six->right      = ten;
    nine->right     = eight;
    eight->left     = three;
    eight->right    = four;

    root = two;
}

void pre_order(Node *node)
{
    stack<Tuples_Stack>st;
    Tuples_Stack t = Tuples_Stack(node,1);
    st.push(t);

    while(!st.empty())
    {
        t = st.top();
        st.pop();

        if(t.p != NULL)
        {
            switch(t.i)
            {
                case 1:
                {
                    t.setI(2);
                    st.push(t);
                    cout << t.getPVal() << " ";
                    break;
                }
                case 2:
                {
                    t.setI(3);
                    st.push(t);
                    Tuples_Stack leftT = Tuples_Stack(t.left(),1);
                    st.push(leftT);
                    break;
                }
                case 3:
                {
                    Tuples_Stack rightT = Tuples_Stack(t.right(),1);
                    st.push(rightT);
                    break;
                }
            }
        }

    }
}


void in_order(Node *node)
{
    stack<Tuples_Stack>st;
    Tuples_Stack t = Tuples_Stack(node,1);
    st.push(t);

    while(!st.empty())
    {
        t = st.top();
        st.pop();

        if(t.p != NULL)
        {
            if(t.i == 1)
            {
                t.setI(2);
                st.push(t);
                Tuples_Stack leftT = Tuples_Stack(t.left(),1);
                st.push(leftT);
            }
            else
            {
                cout << t.getPVal() << " ";
                Tuples_Stack rightT = Tuples_Stack(t.right(),1);
                st.push(rightT);
            }

        }

    }

}

void post_order(Node *node)
{
    stack<Tuples_Stack>st;
    Tuples_Stack t = Tuples_Stack(node,1);
    st.push(t);

    while(!st.empty())
    {
        t = st.top();
        st.pop();

        if(t.p != NULL)
        {
            switch(t.i)
            {
                case 1:
                {
                    t.setI(2);
                    st.push(t);
                    Tuples_Stack leftT = Tuples_Stack(t.left(),1);
                    st.push(leftT);
                    break;
                }
                case 2:
                {
                    t.setI(3);
                    st.push(t);
                    Tuples_Stack rightT = Tuples_Stack(t.right(),1);
                    st.push(rightT);
                    break;
                }
                case 3:
                {
                    cout << t.getPVal() << " ";
                    break;
                }
            }
        }

    }
}

void level_order(Node *node)
{
    queue<Tuples_Queue>qe;
    Tuples_Queue tq = Tuples_Queue(node);
    qe.push(tq);

    while(!qe.empty())
    {
        tq = qe.front();
        qe.pop();

        if(tq.p != NULL)
        {
            cout << tq.getPVal() << " ";

            Tuples_Queue leftT = Tuples_Queue(tq.left());
            qe.push(leftT);

            Tuples_Queue rightT = Tuples_Queue(tq.right());
            qe.push(rightT);
        }
    }
}

int main()
{
    create_tree();

    while(true)
    {
        cout << "1. Pre Order" << endl << "2. In Order" << endl << "3. Post Order" << endl << "4. Level Order" << endl << "5. Exit" << endl;
        cout << "Enter Your Choice: ";

        int choice;
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout<<"Pre order: ";
                pre_order(root);
                cout << endl << endl;
                break;

            case 2:
                cout<<"In order: ";
                in_order(root);
                cout << endl << endl;
                break;

            case 3:
                cout<<"Post order: ";
                post_order(root);
                cout << endl << endl;
                break;

            case 4:
                cout<<"Level order: ";
                level_order(root);
                cout << endl << endl;
                break;

            case 5:
                exit(1);

            default:
                cout << "Wrong Input" << endl << endl;
        }
    }
}
