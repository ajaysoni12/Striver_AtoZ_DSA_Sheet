#include <bits/stdc++.h>
using namespace std;

/* no circular array */
vector<int> nge(vector<int> &arr, int n)
{
    vector<int> nge(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        if (st.empty())
            nge[i] = -1;
        else
            nge[i] = st.top();
        st.push(arr[i]);
    }
    return nge;
}

/* circular array */
vector<int> nge(vector<int> &arr, int n)
{
    vector<int> ans;
    stack<int> s;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i % n])
            s.pop();

        if (i < n)
        {
            if (!s.empty())
                ans.push_back(s.top());
            else
                ans.push_back(-1);
        }
        s.push(arr[i % n]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
    /*  TC-O(n + n + n = 3n)
        SC-O(n) */
}