#include<iostream>
using namespace std;

struct node
{
    int data;
   struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}
node* buildTree(int preorder[],int inorder[],int start,int end){
    static int idx=0;
    if(start>end){
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    node* n=new node(curr);
    int pos=search(inorder,start,end,curr);
    
    if(start==end){
        return n;
    }
    n->left=buildTree(preorder,inorder,start,pos-1);
    n->right=buildTree(preorder,inorder,pos+1,end);
}
void inorderPrint(node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int preorder[]={1,2,4,5,3,6,7};
    int inorder[]={4,2,5,1,6,3,7};
    node* root=buildTree(preorder,inorder,0,6);
    inorderPrint(root);
}