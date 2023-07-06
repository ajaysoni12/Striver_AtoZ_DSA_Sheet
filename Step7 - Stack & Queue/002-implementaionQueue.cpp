#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int front = 0, rear = 0;
    int cnt = 0;
    const static int n = 10;
    int arr[n];

public:
    void push(int val)
    {
        if (cnt == n)
            return;
        arr[rear % n] = val;
        rear++;
        cnt++;
    }
    void pop()
    {
        if (cnt == 0)
            return;
        arr[front % n] = -1; // dummy value
        front++;
        cnt--;
    }
    int top() { return cnt == 0 ? -1 : arr[front % n]; }
    int size() { return cnt; };
    bool isEmpty() { return cnt == 0 ? true : false; }
};