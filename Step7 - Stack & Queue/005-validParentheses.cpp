#include <bits/stdc++.h>
using namespace std;

bool validParentheses(string str)
{
    stack<int> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            st.push(str[i]);
        else
        {
            if (st.empty())
                return false;
            char ch = st.top();
            if ((str[i] == ')' && ch == '(') || (str[i] == ']' && ch == '[') || (str[i] == '}' && ch == '{'))
                st.pop();
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    return false;
    /*  TC-O(n)
        SC-O(n) */
}