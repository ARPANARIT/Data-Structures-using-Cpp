#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

//Construct valid BST from a sorted sequence i.e from its inorder sequence
Node* fromSortedcreateBST(int arr[],int start,int end){
    //find the mid element make it root and recursively call the elements less than mid
    // for left subtree and greater than mid for right subtree.
    //base condition
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    //make it root
    Node* root=new Node(arr[mid]);
    root->left=fromSortedcreateBST(arr,start,mid-1);
    root->right=fromSortedcreateBST(arr,mid+1,end);
    return root;
}
void inorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
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

int main(){
    int arr[]={10,20,30,40,50};
    Node* root1=fromSortedcreateBST(arr,0,4);//start index: 0  end index: 4
    preorderTraversal(root1);
    cout<<endl;
    inorderTraversal(root1);
    cout<<endl;
    return 0;
}