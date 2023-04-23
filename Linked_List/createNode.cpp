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
// FUNCTION TO SEARCH
int search(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {

            return key;
        }
        temp = temp->next;
    }
    return -1;
}
// to delete first node we cannot have n-1th node
void deleteAtHead(Node *&head)
{
    Node *todelete = head;
    head = head->next;
    delete todelete;
}
// FUNCTION TO DELETE
void deleteNode(Node *&head, int val)
{
    // cornered case1
    // where no node is present in the linkedlist
    if (head == NULL)
    {
        return; // cannot do anything
    }
    // cornered case2
    // where only 1 node is present we cannot access n+1th node
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    while (temp->next->data != val)
    { // we are on the n-1th node
        temp = temp->next;
    }
    Node *todelete = temp->next;   // nth node to delete
    temp->next = temp->next->next; // make link between n-1th node to point to n+1th node
    delete todelete;
}
// reverse a linkedlist
Node *reverse(Node *head)
{ // will return a node address and we only have one pointer i.e head

    // initialize 3 pointers
    Node *prev = NULL;
    Node *curr = head;
    Node *next;

    while (curr != NULL)
    {
        // initialize next with pointing to current ka next
        next = curr->next;
        // change the link to reverse
        // curr should point to previous
        // we still do not miss the rest of the linkedlist as next points to the list
        curr->next = prev;

        // make all the 3 pointer to move ahead
        prev = curr;
        curr = next;
        // do not increment next pointer as in the first line of the loop it is incremented
    }
    return prev; // new head
}
// reverse a linkedlist using recursion

Node *reverseRecursive(Node *&head)
{

    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // keep the head and change from head ka next it will give us the rest of the list in reverse
    Node *newhead1 = reverseRecursive(head->next); // 1->2<-3<-4
    head->next->next = head;                       // 1<-2<-3<-4 point 2 to 1
    head->next = NULL;                             // this becomes the last node

    return newhead1;
}
// function to reverse k nodes
// eg 1->2->3->4->5->6
// after reverse of k=2 nodes
//    2->1->4->3->6->5

Node *reversek(Node *&head, int k)
{

    // take 3 pointers to reverse the first k nodes using iterator method
    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    // take a count variable to know where to stop iterating
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // call recursively for the rest of the linkedlist
    // previous is pointing to the last node of the first k nodes and next is pointing to k+1th node
    //  we have 2->1 and 4->3->6->5 we need to point 2->4
    if (next != NULL)
    {
        head->next = reversek(next, k);
    }
    return prev;
}
///////////////////////////////////// DETECT CYCLE FLOYD'S ALGORITHM/////////////////////////////////
bool detectCycle(Node* &head){
    Node* fast=head; //hare 
    Node* slow=head;  // tortoise
    while(fast!=NULL && fast->next!=NULL){ // if cycle is not present fast will be first to traverse the list 
        slow=slow->next;// moves one step at a time
        fast=fast->next->next;//moves two step at a time
        if(fast==slow){// fast and slow both poiting to same node means there is a cycle
            return true;
        }
        
    }
    return false;
}
/////////////// make a cycle function //////////////
void makeCycle(Node* &head, int pos){
    Node* temp=head;
    Node* startNode;// points to start of cycle

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;// last node points to start of the cycle
}
/////////////////Remove cycle///////////////////
void removeCycle(Node* &head){
    // bring the hare and tortoise to point to the same node then hare should point to the head node and then again both should take the steps ahead
    Node* fast=head; //hare 
    Node* slow=head;  // tortoise
    do{ 
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}
////////// function to find Length of Linked list////////
int length(Node* head){
    Node*temp=head;
    int l=0;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

////////////// append last k nodes to start///////

Node* knodes(Node* &head, int k){
    Node*tail=head;
    Node*newHead;
    Node*newTail;
    int leng=length(head);
     k=k%leng;
    int count=1;
    while(tail->next!=NULL){
        if(count==(leng-k)){
            newTail=tail;
        }
        if(count==leng-k+1){
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }
    newTail->next=NULL;
    tail->next=head;
    head=newHead;
    return newHead;
}

int main()
{

    Node *head = NULL;
    insertAtTail(head, 3);
    insertAtTail(head, 36);
    insertAtTail(head, 2);
    insertAtTail(head, 10);
    insertAtTail(head, 9);
    // display(head);
    insertAtHead(head, 111);
    insertAtHead(head, 777);
    insertAtHead(head, 26);
    cout << "New LinkedList" << endl;
    display(head);
    // cout<<"Element: "<<search(head,36)<<endl;
    // deleteNode(head,111);
    // cout<<"After delete operation"<<endl;
    // cout<<"--------------------------"<<endl;
    // deleteAtHead(head);
    // display(head);
    // Node *newHead = reverseRecursive(head);
    // cout << "Reverse LinkedList using recursion" << endl;
    // display(newHead);
    // Node* newHead2=reverseRecursive(head);
    //   cout<<"Reverse LinkedList using recursion"<<endl;

    // display(newHead2);
    // int k=2;
    // Node* newhead3=reversek(head,k);
    // display(newhead3);
    // makeCycle(head,2);
    // cout<<detectCycle(head)<<endl;
    // removeCycle(head);
    // cout<<detectCycle(head)<<endl;
    // display(head);
    cout<<"Length: "<<length(head)<<endl;
   Node* newHead4= knodes(head,2);
    cout<<"last two elements"<<endl;
    display(newHead4);
    return 0;
}