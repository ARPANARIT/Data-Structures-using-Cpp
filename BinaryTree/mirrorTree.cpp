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

/// to mirror the tree 


                /*    2          |          2
                     / \         |         / \
                   3    1        |        1   3 
                  /      \       |       /     \
                 4        5      |      5       4
*/
void mirror(node* nnode) {
      if(nnode==NULL) return;
      mirror(nnode->left);
      mirror(nnode->right);
      node*temp=nnode->left;
      nnode->left=nnode->right;
      nnode->right=temp;
       
        
    }

