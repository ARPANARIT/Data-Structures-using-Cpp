#include <iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


bool getPath(node*root,int key,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==key){
        return true;
    }
    if(getPath(root->left,key,path)||getPath(root->right,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(node* root,int n1,int n2){
    vector<int> path1,path2;//to store the path 
    if(!getPath(root,n1,path1)||!getPath(root,n2,path2)){
        return -1;
    }
    int pc;//pathchange 
    for(pc=0;pc<path1.size()&&path2.size();pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }
    return path1[pc-1];//lca 
}
//////// RECURSIVE WAY TO FIND LCA
node* LCA2(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;// we reached leaf node
    }
    if(root->data==n1|| root->data==n2){
        return root;
    }
    node* leftlca= LCA2(root->left,n1,n2);
    node* rightlca=LCA2(root->right,n1,n2);
    if(leftlca==NULL && rightlca==NULL){
        return NULL; //no lca exists
    }
    if(leftlca&&rightlca){// both left and right lca exist for the current node it is lca
        return root;// this is the lca of n1 and n2
    }
    if(leftlca!=NULL){// only left lca exist
        return leftlca;
    }
    return rightlca;// or else return right lca
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(5);
    root->right->right=new node(6);
    root->right->left->right=new node(7);
    node* lca=LCA2(root,10,7);
    cout<<"LCA: "<<lca->data<<endl;
}