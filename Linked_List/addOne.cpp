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

void insertAthead(Node* &head, int val)
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

Node* reverse(Node*head){
    Node*prev=NULL;
    Node*curr=head;
    Node*next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

//A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.
// 2->3->1    2->3->2 

Node* addNodeUtil(Node*head){
    Node*res=head;
    Node*temp;
    int carry=1,sum;// take initial carry 1
    while(head!=NULL){
        sum=head->data+carry;// add the carry to the head of ll
        carry=(sum>=10)?1:0;//if sum 
        sum=sum%10; //save the remainde at that node
        head->data=sum;
        temp=head;
        head=head->next;
    }
    if(carry>0){
        Node*newNode=new Node(carry);
        temp->next= newNode;
        
    }
    return res;

}



Node* addNode(Node*head){  // 4->3->1
    head=reverse(head);// reverse the ll 1->3->4
   head=addNodeUtil(head); // this returns head of 2->3->4
    return reverse(head);//again reverse the list 4->3->2
    
}

int main(){
    Node*head=NULL;
    insertAtTail(head,9);
    insertAtTail(head,9);
    
    display(head);
   Node* head1=addNode(head);
    display(head1);
}