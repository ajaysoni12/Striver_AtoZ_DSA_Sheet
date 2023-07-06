#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int _val)
    {
        data = _val;
        left = right = NULL;
    }
};

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);

    /*
            1
           2  3
            4
    */

    return 0;
}