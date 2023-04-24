#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* insertAtBST(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){ // if our node has val less than root it should reside in the left subtree
        root->left=insertAtBST(root->left,val);
    }
    else{ // if our node has val greater than root it should reside in the right subtree
        // new node in root right 
        root->right=insertAtBST(root->right,val);
    }
    return root;
}
void inorderTraversal(Node*root){// inrder of BST is always a sorted order
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
    

}
/////// find Inorder Successor of a node
Node* inorderSuccessor(Node* root){
    Node* curr=root;
    while(curr&&curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}



/////////// delete a node in BST ////////
Node* DeleteBst(Node* root, int key){
    //if key is less than roots data search and delete in left subtree
    if(key<root->data){
        root->left=DeleteBst(root->left,key);
    }
    //if key is greater than roots data search and delete in right subtree
    else if(key>root->data){
        root->right=DeleteBst(root->right,key);
    }
    else{
        //Case 1 and 2 where the root has one or no child
    if(root->left==NULL){// the node must have right child
        Node* temp=root->right;// store the right child
        free(root);
        return temp;
    }
     else if(root->right==NULL){// the node must have left child
        Node* temp=root->left;// store the left child
        free(root);
        return temp;
    }
    // Case 3: where node to delete has two child 
    // find the inorder successor and replace it with inorder successor
    else{
        Node* temp= inorderSuccessor(root->right);
        root->data=temp->data; //replace the nodes value with its successor
        root->right=DeleteBst(root->right,temp->data);// delete the successor
    }
    }
return root;

    
}




/*
                    5 <- root
                 /     \
              1          7
                \         \  
                  4         8
                /   \
              2       3
*/ 
int main(){
    Node* root=NULL;
    root=insertAtBST(root,5);
    insertAtBST(root,1);
    insertAtBST(root,4);
    insertAtBST(root,2);
    insertAtBST(root,3);
    insertAtBST(root,7);
    insertAtBST(root,8);
    inorderTraversal(root);
    Node* root1=DeleteBst(root,4);
    cout<<endl;
    inorderTraversal(root1);
    return 0;
}