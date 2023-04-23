#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int prefixNotation(string s)
{
    stack<int> st;
    for (int i = s.length()-1; i >= 0; i--)
    {
        if (s[i]>='0' && s[i] <= '9')
        {                      //// to detect it is an operand
            s[i] = s[i] - '0'; //// ascii value
            st.push(s[i]);
        }
        else
        {
            int opr1 = st.top();
            st.pop();
            int opr2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(opr1 + opr2);
                break;
            case '-':
                st.push(opr1 - opr2);
                break;
            case '/':
                st.push(opr1 / opr2);
                break;
            case '*':
                st.push(opr1 * opr2);
                break;
            case '^':
                st.push(pow(opr1, opr2));
                break;

           
            }
        }
    }
    return st.top();
}

int main()
{
    cout<<prefixNotation("-+7*45+20")<<endl;
        cout<<prefixNotation("+*423")<<endl;

    return 0;
}