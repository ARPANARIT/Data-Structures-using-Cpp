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

class myStack{
    node* head;
    int size;
    public:
    myStack(){
        head=NULL;
        size=0;
    }
    void Push(int x){
        node* newNode= new node(x);
        if(head==NULL){
            head=newNode;
        }
        newNode->next=head;
        head=newNode;
        size++;
    }
    int Pop(){
        if(head==NULL) return -1;
        node* todel=head;
        int d=head->data;
        head=head->next;
        delete(todel);
        size--;
        return d;
    }
    int Size(){
        return size;
    }
    int Peek(){
        if(head==NULL){
            return -1;
        }
        return head->data;
    }
    void isEmpty(){
        if(head==NULL){
            cout<<"Empty"<<endl;
        }
        cout<<"Not Empty"<<endl;
    }
};
int main(){
    myStack st;
    st.Push(1);
    cout<<st.Peek()<<endl;
    st.isEmpty();
    cout<<st.Size()<<endl;
    return 0;
}