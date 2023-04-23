#include<iostream>
#include<queue>
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
int sumAtK(node*root,int k){
    if(root==NULL){
        return -1;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while(!q.empty()){
        node* n=q.front();
        q.pop();
        if(n!=NULL){
            if(level==k){

            sum+=n->data;
            }
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
             }
        }
        else if(!q.empty()){
            //It is null object encountered but queue not empty denotes we have covered a level traversal
            level++;
            q.push(NULL);
        }

    }
    return sum;
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->right=new node(5);
    cout<<sumAtK(root,1)<<endl;
}