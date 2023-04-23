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

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    if(head!=NULL){

    n->next=head;
    }
    head=n;
    
}
void insertAtTail(node*head,int val){
    node* n=new node(val);
    node*temp=head;
    if(head==NULL){
        insertAtHead(head,val);
    }
    while (temp->next!=NULL)
    {
        temp=temp->next;
        
    }
        temp->next=n;
    
}
void display(node* head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}


void makeloop(node* &head, int pos){
    node*startNode;
    node*temp=head;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

bool detectloop(node* head){
    node*fast=head;
    node* slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    
        if(slow==fast){
            return true;
        }
    }
    return false;
}
bool detectCycle(node* &head){

    node* fast=head; //hare 
    node* slow=head;  // tortoise

    while(fast!=NULL && fast->next!=NULL){ // if cycle is not present fast will be first to traverse the list 
        slow=slow->next;// moves one step at a time
        fast=fast->next->next;//moves two step at a time

        if(fast==slow){// fast and slow both poiting to same node means there is a cycle
            return true;}}
        return false;}

void removeloop(node* head){
    node*fast=head;
    node* slow=head;
    do
    {
     slow=slow->next;  
     fast=fast->next->next;
    } while (slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
    
}
int main(){
    node* head=NULL;
    int arr[5]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        insertAtHead(head,arr[i]);
    }
    display(head);
    makeloop(head,2);
    cout<<detectloop(head)<<endl;
    removeloop(head);
    display(head);
    //cout<<detectloop(head)<<endl;
    cout<<detectCycle(head)<<endl;
   // display(head);
        return 0;
    }