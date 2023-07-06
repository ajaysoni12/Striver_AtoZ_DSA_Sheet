#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    const static int n = 1e5 + 10;
    int top = -1;
    int arr[n];

public:
    void push(int val) { arr[++top] = val; };
    void pop() { --top; };
    int top() { return top == -1 ? top : arr[top]; };
    int size() { return top + 1; };
    bool isEmpty() { return top == -1 ? true : false; };
};