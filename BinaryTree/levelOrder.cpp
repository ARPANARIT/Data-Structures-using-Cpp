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
void levelOrderPrint(node* root){
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty()){
        node* n=q1.front();
        q1.pop();
        if(n!=NULL){
            cout<<n->data<<" ";
            if(n->left){
                q1.push(n->left);
            }
            if(n->right){
                q1.push(n->right);
             }
        }
        else if(!q1.empty()){
            q1.push(NULL);
        }
    }
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->right=new node(5);
    levelOrderPrint(root);
}