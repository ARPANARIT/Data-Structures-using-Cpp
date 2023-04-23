#include<iostream>
using namespace std;

struct node
{
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int countNode(node* root){
    if(root==NULL){
        return 0;
    }
    return countNode(root->left)+countNode(root->right)+1;
}

int sumNodes(node* root){
    if(root==NULL){
        return 0;
    }
    return sumNodes(root->left)+sumNodes(root->right)+root->data;
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->right=new node(5);
    cout<<"Count: "<<countNode(root)<<endl;
    cout<<"Sum: "<<sumNodes(root)<<endl;
}