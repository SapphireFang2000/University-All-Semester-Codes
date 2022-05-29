#include<bits/stdc++.h>
using namespace std;

int temp = 0;

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

void create_tree()
{
    Node *sixty   = new Node(60);
    Node *forty = new Node(40);
    Node *sixty_five  = new Node(65);
    Node *thirty   = new Node(30);
    Node *fifty   = new Node(50);
    Node *seventy = new Node(70);
    Node *thirty_five   = new Node(35);
    Node *sixty_eight = new Node(68);
    Node *seventy_five = new Node(75);

    sixty->left       = forty;
    sixty->right      = sixty_five;
    forty->left     = thirty;
    forty->right    = fifty;
    sixty_five->right = seventy;
    seventy->left       = sixty_eight;
    seventy->right      = seventy_five;
    thirty->right    = thirty_five;

    root = sixty;
}


void pre_order(Node *node, int value)
{
    if(node == NULL)
        return;

    if(node->data == value)
    {
        temp = 1;
    }

    pre_order(node->left, value);
    pre_order(node->right, value);
}

int main()
{
    int value;

    create_tree();

    cout << "Enter the value to search in the tree: ";
    cin >> value;

    pre_order(root, value);

    if(temp == 1)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}
