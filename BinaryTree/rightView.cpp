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
void rightview(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node* curr=q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}
int main(){
    node* root1=new node(1);
    root1->left=new node(2);
    root1->right=new node(3);
    root1->left->right=new node(4);
    root1->left->right->right=new node(5);
    rightview(root1);
}