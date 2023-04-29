#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void zigzagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> currLevel;
    stack<Node *> nextLevel;
    bool leftToRight = true;
    currLevel.push(root);

    while (!currLevel.empty())
    {
        Node *n = currLevel.top();
        currLevel.pop();

        cout << n->data << " ";

        if (leftToRight)
        {

            if (n->left)
            {
                nextLevel.push(n->left);
            }
            if (n->right)
            {
                nextLevel.push(n->right);
            }
        }
        else
        {

            if (n->right)
            {
                nextLevel.push(n->right);
            }
            if (n->left)
            {
                nextLevel.push(n->left);
            }
        }
        // after one level completion
        if (currLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}

int main()
{
    Node *root = new Node(7);
    root->left = new Node(5);
    root->right = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(9);
    zigzagTraversal(root);
}