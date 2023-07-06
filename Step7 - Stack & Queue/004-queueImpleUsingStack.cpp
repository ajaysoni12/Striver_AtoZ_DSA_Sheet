#include <bits/stdc++.h>
using namespace std;

/*  using two stack
    push(x)
        -> s1->s2
        -> x->s1
        -> s2->s1

    pop()
        ->s1.pop()

    //  TC-O(n) SC-O(2n) //
*/

/* better time complexity */
stack<int> input, output;
void push(int val)
{
    input.push(val);
}
void pop()
{
    if (output.empty() == false)
        output.pop();
    else
    {
        while (input.empty() == false)
        {
            output.push(input.top());
            input.pop();
        }
        output.pop();
    }
}
int top()
{
    if (output.empty() == false)
        return output.top();
    else
    {
        while (input.empty() == false)
        {
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }
}