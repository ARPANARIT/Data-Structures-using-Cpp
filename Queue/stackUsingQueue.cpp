#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
    int N;
    public:
    Stack(){
        N=0;
    }
    void Push(int x){
        /////// push it into q2 
        q2.push(x);
        N++;
        ///// pop and push elements from q1 to q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();

        }
        /// swap q1 and q2
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }
    void pop(){
        q1.pop();// my last element is at the front of the q1 as by lifo of stack we pop the last element
        N--;
    }
    int top(){
        return q1.front();
    }
    int size(){
        return N;
    }
};

int main(){
    Stack st;
    st.Push(1);
    st.Push(3);
    st.Push(36);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    return 0;
}
