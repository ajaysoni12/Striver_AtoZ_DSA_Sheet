#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/* apply inordertraversal-store ans-find kth smallest/greatest */
/* apply inorder traversal-symultanously cnt */
/* apply morries traveresal for eliminating stack space */

int cnt = 0;
Node *ans = NULL;
Node *kthSmallestEle(Node *root, int k)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cnt++;
            if (cnt == k)
                ans = curr;
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                cnt++;
                if (cnt == k)
                    ans = curr;
                curr = curr->right;
            }
        }
    }
    return ans;
}
