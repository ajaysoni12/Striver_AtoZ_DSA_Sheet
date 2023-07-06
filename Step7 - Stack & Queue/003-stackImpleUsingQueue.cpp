#include <bits/stdc++.h>
using namespace std;

/* using two queue */
queue<int> q2, q3;
void push(int val)
{
    q3.push(val);
    while (!q2.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q2, q3);
}
void pop() 
{
    q2.pop(); 
}

/* using single queue */
queue<int> q1;
void push(int val)
{
    q1.push(val);
    for (int i = 0; i < q1.size() - 1; i++)
    {
        q1.push(q1.front());
        q1.pop();
    }
}
void pop()
{
    q1.front();
}
int top()
{
    return q1.front();
}