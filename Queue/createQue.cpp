#include <iostream>
using namespace std;
#define n 20
class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1; // 
        back = -1; // 
    }
    void push(int x)
    {
        if (back == n - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }
    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "NOTHING TO POP" << endl;
            return;
        }
        front++;
    }
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "NOTHING TO Peek" << endl;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue Empty" << endl;
            return true;
        }
        return false;
    }
       void display()
    {
        if (empty())
        {
            return;
        }
        for (int i = front; i <= back; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
// q.display();
   cout<<q.peek()<<endl;; /// 1
    q.pop();
    cout<<q.peek()<<endl;; /// 2
    q.pop();
    cout<<q.peek()<<endl; // 3
    q.pop();
   cout<<q.peek()<<endl; // 4
    return 0;
}
