#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/* apply inorder tarversal-store and return */
/* apply iorder symultanously reduce k, where k will be 0 return curr node */

int ans = 0;
int kthLargest(Node *r, int &k)
{
    if (!r || k < 0)
        return 0;
    kthLargest(r->right, k);
    if (--k == 0)
        return ans = r->data;
    kthLargest(r->left, k);
    return ans;
    /*  TC-O(n) SC-o(height of tree) */
}