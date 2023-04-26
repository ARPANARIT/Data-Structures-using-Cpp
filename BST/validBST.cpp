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

// check if given bst is a valid binary search tree or not
bool checkBst(Node*root,Node*min,Node*max){
    if(root==NULL){
        return true;// leaves always follow rules of bst
    }
    if(min!=NULL && root->data<=min->data){
        return false;// if my root node is less than my minimums node data it is not bst
    }
    if(max!=NULL && root->data>=max->data){
        return false;//roots data cannot be large than its right subtree
    }
    bool leftTree=checkBst(root->left,min,root);
    bool rightTree=checkBst(root->right,root,max);

    return leftTree && rightTree;//if both comes true the tree is a valid bst
}
// utility function to create bst
Node* insertAtBST(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){ // if our node has val less than root it should reside in the left subtree
        root->left=insertAtBST(root->left,val);
    }
    else{ // if our node has val greater than root it should reside in the right subtree
        // new node in root right 
        root->right=insertAtBST(root->right,val);
    }
    return root;
}
int main(){

    Node* root=new Node(2);
    root->left=new Node(1);
    root->right=new Node(3);
    if(checkBst(root,NULL,NULL)){
        cout<<"valid Binary Search Tree"<<endl;
    }
    else{
        cout<<"Not a Valid BST"<<endl;
    }
}