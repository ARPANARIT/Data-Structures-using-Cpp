#include <iostream>
using namespace std;
 
void fun(int x)
{
    if(x > 0)//works like a tree 
    {
        fun(--x);//left is called
        cout << x <<" ";//root is printed
        fun(--x);//right is called
        
    }
}
 
int main()
{
    int a = 4;
    fun(a);
    return 0;
}