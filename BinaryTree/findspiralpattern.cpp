#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left,right=NULL;
    }
};

// function returns a list with level order spiral traversal
vector<int> findSpiral(node *root)
{
    if(!root) 
    return {};
    vector<int> ans;
    queue<node *>q;
    q.push(root);
    int flag=1;
    while(!q.empty())
    {
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            node* node=q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        size=q.size();
        if(flag)
        {
            reverse(level.begin(),level.end());
            flag=0;
        }
        else{
            flag=1;
        }
        for(int num:level)
        {
            ans.push_back(num);
        }
    }
    return ans;
}

int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right->left=new node(60);
    root->right->right=new node(70);
    vector<int> res=findSpiral( root);
    for(int i=0;i<res.size();i++){
        cout<<res.at(i)<<" ";
    }
    cout<<endl;
    return 0;
}
