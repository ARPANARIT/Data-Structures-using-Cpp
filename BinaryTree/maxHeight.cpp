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
////// time complexity : o(n)
int calHeight(node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight=calHeight(root->left);
    int rHieght=calHeight(root->right);
    return max(lHeight,rHieght)+1;
}
////Time complexity : o(n2)
int calDiameter(node*root){
    if(root==NULL){
        return 0;
    }
    int leftH=calHeight(root->left);
    int rightH=calHeight(root->right);
    int currdia=leftH+rightH+1;

    int leftdia=calDiameter(root->left);
    int rightdia=calDiameter(root->right);

    return max(currdia,max(leftdia,rightdia));
}
///optimized way in which calculating height along diameter
int calDia(node*root, int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int leftdia=calDia(root->left,&lh);
    int rightdia=calDia(root->right,&rh);
    *height=max(lh,rh)+1;
   
    int currdia=lh+rh+1;

    return max(currdia,max(leftdia,rightdia));

}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->right=new node(5);
   root->left->left->left=new node(6);
   root->left->left->left->left=new node(7); 
    //cout<<calHeight(root)<<endl;
    //cout<<calDiameter(root)<<endl;
    int height=0;
    cout<<calDia(root,&height)<<endl;
}