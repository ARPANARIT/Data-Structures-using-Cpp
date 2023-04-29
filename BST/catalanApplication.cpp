#include <iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
//                              
vector<Node*> constructTree(int start, int end){
    vector<Node*> Trees;
    //base case
    if(start>end){
        Trees.push_back(NULL);
        return Trees;
    }
    for(int i=start;i<=end;i++){
        // first construct bsts for n=1 and n=2 and then combine them with 3rd node to form possible bsts
        vector<Node*> leftsubtree=constructTree(start,i-1);
        vector<Node*> rightsubtree=constructTree(i+1,end);
//combine every possible left subtree with the right
        for(int j=0;j<leftsubtree.size();j++){
            Node* left=leftsubtree[j];
            for(int k=0;k<rightsubtree.size();k++){
                Node* right=rightsubtree[k];
                Node* newNode=new Node(i);
                newNode->left=left;
                newNode->right=right;
                Trees.push_back(newNode);
            }
        }
    }
    return Trees;
}// node pointer for every bst's root
void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
int main(){
    vector<Node*> totalTrees=constructTree(1,4);
    for(int i=0;i<totalTrees.size();i++){
        cout<<(i+1)<<":"<<" ";
        preorderTraversal(totalTrees[i]);
        cout<<endl;

    }

}