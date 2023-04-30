#include <iostream>
#include<stack>
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
Node* search(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {

            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
// if you are given a pointer/reference to a node which is to be deleted in the LL
// strategy make a temp ptr pointing to the next node which is to be deleted
//copy the data of the next to the node which is to be deleted
// change the link of delete's next to point to temp's next 
// finally delete node

   void deleteNode(Node *del)
    {
       // Your code here
       Node*temp=del->next;
       del->data=temp->data;
       del->next=temp->next;
       delete(temp);
    }



int main(){

    Node* head=NULL;
    insertAtTail(head,16);
    insertAtTail(head,26);
    insertAtTail(head,36);
    insertAtTail(head,46);
    insertAtTail(head,56);
    display(head);
    Node* todel=search(head,26);
    deleteNode(todel);
    display(head);
    return 0;
}