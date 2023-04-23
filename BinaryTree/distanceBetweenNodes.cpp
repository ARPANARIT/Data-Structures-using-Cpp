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
node* Lca(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;// we reached leaf node
    }
    if(root->data==n1|| root->data==n2){
        return root;
    }
    node* leftlca= Lca(root->left,n1,n2);
    node* rightlca=Lca(root->right,n1,n2);
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
///// Function to find distance/////
int findDist(node* root, int k, int dist){
    if(root==NULL){
        return -1;// we didnt find k
    }
    if(root->data==k){
        return dist; // return current level
    }
    int left=findDist(root->left,k,dist+1);// find k in left subtree now the level increased by one
    if(left!=-1){
        return left;
    }
    return findDist(root->right,k,dist+1);
}


int distancebtwNodes(node* root,int n1,int n2){
    node*lca=Lca(root,n1,n2);
    int d1=findDist(lca,n1,0);//curr dist =0 from lca to n1
    int d2=findDist(lca,n2,0);
    return d1+d2;
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->right=new node(5);
    cout<<distancebtwNodes(root,1,1)<<endl;
}