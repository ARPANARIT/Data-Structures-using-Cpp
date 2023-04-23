#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
// FUNCTIONS FOR INSERT
void insertAtTail(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}

// FUNCTION TO DISPLAY
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {                               // temp pointing to the NULL variable and it should not be temp->next!=NuLL
        cout << temp->data << "->"; // after reaching the last node temp->next==Null and does not enter the loop
        temp = temp->next;          // and the last node does not prints
    }
    cout << "NULL" << endl;
}
//////////////////Function for making intersection/////////
void intersection(Node *head1, Node *head2, int pos)
{
    Node *temp = head1;
    pos--;
    while (pos--)
    {
        temp = temp->next;
        
    }
    Node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}
int length(Node *&head)
{
    int l = 0;
    Node *temp = head;
    while (temp->next != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
int detectIntersection(Node *&head1, Node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    Node *ptr1;
    Node *ptr2;
    if (l1 > l2)
    {
         d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
         d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
////////////// merge two sorted linked list////////////
Node* merge(Node* &head1,Node* &head2){
    Node* ptr1=head1;
        Node* ptr2=head2;
        Node* dummy= new Node(-1);
        Node*ptr3=dummy;
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->data<ptr2->data){
                ptr3->next=ptr1;
                ptr1=ptr1->next;
            }
            else{
                ptr3->next=ptr2;
                ptr2=ptr2->next;
            }
            ptr3=ptr3->next;
            
        }
        while(ptr1!=NULL){
                ptr3->next=ptr1;
                ptr1=ptr1->next;
                ptr3=ptr3->next;
            }
            while(ptr2!=NULL){
                ptr3->next=ptr2;
                ptr2=ptr2->next;
                ptr3=ptr3->next;
            }
            return dummy->next;

}
Node* mergeRecursive(Node* head1,Node* head2){
    Node*result;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
        else{
            result=head2;
            result->next=mergeRecursive(head1,head2->next);
        }
    return result;
}
int main()
{

    Node *head1 = NULL;
    Node *head2 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 36);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head2, 11);
    insertAtTail(head1, 21);
    insertAtTail(head2, 31);
    insertAtTail(head2, 361);
    insertAtTail(head2, 41);
    // insertAtTail(head2,51);
    //display(head1);
    //display(head2);
    intersection(head1, head2, 5);
    //display(head2);
   // cout<<detectIntersection(head1,head2)<<endl;
   Node* head3=NULL;
   insertAtTail(head3,1);
   insertAtTail(head3,4);
   insertAtTail(head3,5);
   insertAtTail(head3,7);
   Node* head4=NULL;
   insertAtTail(head4,2);
   insertAtTail(head4,3);
   insertAtTail(head4,6);
   display(head3);
   display(head4);
   Node* mergedNode=mergeRecursive(head3,head4);
   display(mergedNode);

    return 0;
}