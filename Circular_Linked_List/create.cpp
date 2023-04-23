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
    if(head==NULL){
        n->next=n;
        head=n;
    }
    node* temp =head;
    while(temp->next!=head){
         temp= temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
void insertAtTail(node* &head,int val){
    node*n=new node(val);
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* temp=head;
    while(temp->next!=head){
         temp= temp->next;
    }
    temp->next=n;
    n->next=head;
}

void display(node* &head){
    node*temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<endl;
}
void displayLast(node* &head){
    node*temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    
}
void deleteAtHead(node* &head,int pos){
    node* todelete=head;
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head->next;
    head=head->next;
    delete todelete;

}
void deletion(node* &head,int pos){
    if(pos==1){
        deleteAtHead(head,pos);
        return;
    }
    node* temp=head;
    int count=1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
     node* todelete=temp->next;
     temp->next=temp->next->next;
     delete todelete;
}

int main(){
    int arr[15]={1,21,43,54,67,36,78,90,101,2,89,333,777,111,10};
    node* head1=NULL;
    for(int i=0;i<15;i++){
        insertAtTail(head1,arr[i]);
    }
    display(head1);
    //displayLast(head1);
    deletion(head1,7);
    display(head1);
    return 0;
}