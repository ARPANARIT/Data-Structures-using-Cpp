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
bool isPalindrome(Node *head)
    {
        //Your code here
        stack<int> s;
        Node*temp=head;
        while(temp!=NULL){
            s.push(temp->data);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            int n=s.top();
            if(n!=temp->data){
                return false;
            }
            s.pop();
            temp=temp->next;
        }
        return true;
    }
int main(){

    Node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,1);
    insertAtTail(head,3);
    cout<<isPalindrome(head)<<endl;
    return 0;
}