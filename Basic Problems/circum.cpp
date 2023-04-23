#include<iostream>
using namespace std;

void circle(int radius)
{
    cout << "Perimeter is "<<2*3.14*radius<<"\n";
    cout << "Area is "<<3.14*radius*radius<<"\n";
}

int main()
{   int r;
    cin >> r;
    circle(r);
    return 0;
}			