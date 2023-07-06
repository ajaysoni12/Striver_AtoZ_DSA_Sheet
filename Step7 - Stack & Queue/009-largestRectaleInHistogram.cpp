#include <bits/stdc++.h>
using namespace std;

int largestRecArea(vector<int> &height)
{
    int n = height.size();
    stack<int> st;

    int leftSmall[n], rightSmall[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= height[i])
            st.pop();

        if (st.empty())
            leftSmall[i] = 0;
        else
            leftSmall[i] = st.top() + 1;

        st.push(i);
    }

    // reused stack
    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && height[st.top()] >= height[i])
            st.pop();

        if (st.empty())
            rightSmall[i] = n - 1;
        else
            leftSmall[i] = st.top() - 1;

        st.push(i);
    }

    int maxA = 0;
    for (int i = 0; i < n; i++)
        maxA = max(maxA, height[i] * (rightSmall[i] - leftSmall[i] + 1));

    return maxA;
    /*  TC-O(n + n + n = 3n)
        SC-O(n) */
}

/* otptimize */
int largestRecArea(vector<int> &arr, int n)
{
    stack<int> st;
    int maxA = 0;

    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || arr[st.top()] >= arr[i]))
        {
            int height = arr[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
        }
        st.push(i);
    }
    return maxA;
    /*  TC-O(n)
        SC-O(n) */
}