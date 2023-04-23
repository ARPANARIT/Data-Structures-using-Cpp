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

node* reverse(node* &head){

    node*prev=NULL;
    node*curr=head;
    node*next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void insertAt(node* &head,int val,int key){
    node* n=new node(val);
    node* temp=head;
    while(temp->data!=key){
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}

node* recursiveReverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newHead=recursiveReverse(head->next);
    head->next->next=head; //1 -> 2 -> 3 <- newHead
    // to change the 1->2 to 2<-1 
    head->next=NULL;// becomes the last node
    return newHead;
}

node* reversek(node*head, int k){
    node*prev=NULL;
    node*curr=head;
    node*next;
    int count=0;
    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
    head->next =reversek(next,k);
    }
    
    return prev;
}
int main(){
    node* head=NULL;
    int arr[5]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        insertAtHead(head,arr[i]);
    }
   // display(head);
    // node* newHead1=reverse(head);
    // display(newHead1);
    // insertAtTail(head,36);
    // display(head);
    insertAt(head,36,3);
    //display(head);
    insertAt(head,36,4);
    display(head);
    // insertAtHead(head,36);
    // display(head);
    // node* n2=recursiveReverse(head);
    // display(n2);
    node* n3=reversek(head,2);
    display(n3);
    return 0;
}