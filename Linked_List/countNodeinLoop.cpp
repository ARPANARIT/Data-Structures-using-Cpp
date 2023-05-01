#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
       next=NULL;
    }
};

int countNodes(node*head){
    node*fast=head;
    node*slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){//loop os present
            int count=1;
            slow=slow->next;//keep the fast at that place and move the slow again it meets fast 
            while(slow!=fast){
                count++;//keep counting
                slow=slow->next;
            }
            return count;
        }
    }
    return 0;//theres no loop
}
