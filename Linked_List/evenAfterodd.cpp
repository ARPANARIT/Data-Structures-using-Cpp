#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};


void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}
void insertAttail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAthead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}
////////////////Function even positioned elements after odd/////////////
void evenAfterOdd(node* &head){
    node* odd=head;
    node* even=head->next;
    node*evenStart=even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenStart;
    if(odd->next==NULL){
        even->next=NULL;
    }
}
int main(){
    int arr[7]={1,2,3,4,5,6,7};
    node* head=NULL;
    for(int i=0;i<7;i++){
        insertAttail(head,arr[i]);
    }
        display(head);
        evenAfterOdd(head);
        display(head);
}