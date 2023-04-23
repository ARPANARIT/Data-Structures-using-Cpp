#include<iostream>
#include<queue>
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

int countNodesofTree(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int count=0;
   
    while(!q.empty()){
         node* n=q.front();
    q.pop();
        if(n!=NULL){
            count++;
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
    return count;
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    
    cout<<countNodesofTree(root)<<endl;
}