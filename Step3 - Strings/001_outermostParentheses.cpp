#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using observation) */
string removeOuterParen(string &s)
{
    int start = 0; // keep track of start outermost parentheses
    int open = 0;  // count open brackets

    string ans = "", temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            open++;
        else
            open--;

        // if open brackets is zero, than add all innerbrackets(temp)
        if (open == 0)
        {
            ans += temp;
            temp = "";
            start = i + 1; // set next outermost parentheses
        }

        // add all element if i > start, start point outermost paren
        if (i > start)
            temp += s[i];
    }
    return ans;
    /*  TC-O(n)
        SC-O(n) */
}

/* method 2 (optimize solution: using stack) */
string removeOuterParen(string &s)
{
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        // outermost parentheses
        if (s[i] == '(' and st.empty())
            st.push(s[i]);

        // inner parentheses
        if (s[i] == '(')
        {
            ans += '(';
            st.push('(');
        }
        else if (s[i] == ')')
        {
            st.pop();

            // inner parenetheses
            if (st.size() > 0)
                ans += ')';
        }
    }
    return ans;
    /*  TC-O(n)
        SC-O(n) */
}