#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
    int N;
    public:
    Stack(){
        N=0;// intially size is 0
    }
    void pop(){
        if(q1.empty()){
            return ;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();// this is the element we want to pop
        N--;
        // swap the q1 and q2
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
        
    }
    void push(int x){
        q1.push(x);
        N++;
    }
    int top(){
        if(q1.empty()){
            return -1;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int res=q1.front();
        q2.push(res);
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
        return res;
    }
    int size(){
        return N;
    }
    };

    int main(){
        Stack st;
        st.push(3);
        st.push(36);
        st.push(15);
        st.push(24);
        cout<<st.top()<<endl;
        st.pop();
        cout<<st.top()<<endl;
        st.pop();
        cout<<st.top()<<endl;
        st.pop();
        cout<<st.top()<<endl;
        st.pop();
        cout<<st.size()<<endl;
        
    }