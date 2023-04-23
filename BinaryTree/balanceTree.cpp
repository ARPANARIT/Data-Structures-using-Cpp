#include <iostream>
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
bool isBalance(node* root, int* height){
    if(root==NULL){
        return true;// leaf node are balanced
    }
    int lh=0,rh=0;
    if(isBalance(root->left,&lh)==false){
        return false;
    }
    if(isBalance(root->right,&rh)==false){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    return false;
}
int main(){
    node* root1=new node(1);
    root1->left=new node(2);
    root1->right=new node(3);
    root1->left->right=new node(4);
    root1->left->right->right=new node(5);
    int height=0;
    if(isBalance(root1,&height)){
        cout<<"Balanced Tree";
    }
    else{
        cout<<"Unbalance";
    }
    }