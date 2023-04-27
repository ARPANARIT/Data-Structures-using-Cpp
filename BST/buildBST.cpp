#include <iostream>
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

// Build BST from its preorder sequence
// we do not need its inorder as we need to construct normal binary tree
// because inorder of BST is sorted order sequence
Node *buildBST(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{
    if (*preorderIdx >= n)
    {
        return NULL; // we have traversed our preorer array
    }
    Node *root = NULL;
    if (key > min && key < max)
    { // our current node satisfies condition defined by parents
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;
        if (*preorderIdx < n)
        {
            root->left = buildBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
            // any node with value less than parent node or key should lie in left subtree
        }
        if (*preorderIdx < n)
        {
            root->right = buildBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }

    return root;
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx = 0;
    Node *root1 = buildBST(preorder, &preorderIdx, preorder[0], INT8_MIN, INT8_MAX, n);
    preorderTraversal(root1);
    return 0;
}