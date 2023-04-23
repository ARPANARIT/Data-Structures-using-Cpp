#include<iostream>
using namespace std;
#define n 20

class queue{
    int *arr;
    int front;
    int back;
    public:
    queue(){
        arr=new int[n];
        front=-1;
        back=-1;

    }
    void enqueue(int x){
        if(front==-1 && back==-1){
            front++;
            back++;
            arr[back]=x;
        }
        if(back!=n-1){

        back++;
        arr[back]=x;
        }
    }
    int dequeue(){
        if(front==-1||front>back){
            cout<<"NO ELEMENTS TO REMOVE"<<endl;
            return -1;
        }
        front++;

    }
    int peek(){
        if(front==-1||front>back){
            cout<<"NO ELEMENTS TO PEEK"<<endl;
            return -1;
        }
        cout<<arr[front]<<endl;
    }
    bool isEmpty(){
        if(front==-1||front>back){
            cout<<"NO ELEMENTS IN QUEUE"<<endl;
            return true;
        }
        return false;
    }
};

int main(){

    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.peek();
    q.isEmpty();
    return 0;
}