#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* insertAtBST(Node* root, int val){
    if(root=NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertAtBST(root->left,val);
    }
    else{
        // new node in root right 
        root->right=insertAtBST(root->right,val);
    }
    return root;
}
void inorderTraversal(Node*root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
    cout<<endl;

}
int main(){
    Node* root=NULL;
    root=insertAtBST(root,5);
    insertAtBST(root,1);
    insertAtBST(root,3);
    insertAtBST(root,4);
    insertAtBST(root,2);
    insertAtBST(root,7);
    insertAtBST(root,8);
    inorderTraversal(root);
    return 0;
}