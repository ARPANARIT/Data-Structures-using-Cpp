#include<iostream>
using namespace std;

struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};

/*three functions to solve merge sort in Linked list
1. the actual mergesort() which splits the list in halves and stores the reference of the first node of each halves.
2. splitList() which divides the linked list in half
3. merge() which merges two sorted Linkedlist and returns head pointing to the first node of the LinkedList.


*/
void splitList(Node* source, Node** firstList, Node** secList){
        Node*slow;
        Node*fast;
// if the list has no or one node return oooonly the first list & declare the second list Null
        if(source==NULL || source->next==NULL){
            *firstList=source;
            *secList=NULL;
        }
        else{
// want to find the mid of LinkedList use fast and slow pointer approach
            slow=source;
            fast=source->next;
            while(fast!=NULL){
                fast=fast->next;
                if(fast!=NULL){
                    fast=fast->next;
                    slow=slow->next;
                }
            }
            *firstList=source;
            *secList=slow->next;
            slow->next=NULL;
        }
        
    }
    // Merge two sorted arrays recursion version
    Node* merge(struct Node*a, struct Node*b){
        Node*result=NULL;
        if(a==NULL) return b;
        else if(b==NULL) return a;
        else{
            if(a->data<=b->data){
                result=a;
                result->next=merge(a->next,b);
            }
            else{
                result=b;
                result->next=merge(a,b->next);
            }
        }
        return result;
    }
   Node* mergeSort(Node* head){
       struct Node* a;
       struct Node* b;
       if(head==NULL || head->next==NULL){
           return head;
       }
       splitList(head,&a,&b);
       a=mergeSort(a);
       b=mergeSort(b);
      return merge(a,b);
       
   }

