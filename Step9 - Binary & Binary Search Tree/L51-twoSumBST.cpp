#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/*  method 1-store inorder(sorted)-apply two pointer technique
    TC-O(n) SC-O(n) */

/*  method 2 (using set or hashing) */

/*  method 2 */
class BSTIterator
{
private:
    stack<Node *> st;
    bool reverse = true; // true-before, false-next
    void pushAll(Node *root)
    {
        while (root != NULL)
        {
            st.push(root);
            root = reverse == true ? root->right : root->left;
        }
    }

public:
    BSTIterator(Node *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root); // insert all left nodes
    }

    // return true, if next node have, otherwise return false
    bool hasNext()
    {
        return !st.empty();
    }

    // return the next smallest element
    int next()
    {
        Node *temp = st.top();
        st.pop();
        reverse == true ? pushAll(temp->left) : pushAll(temp->right); // push all left element
        return temp->data;

        /*  TC-O(1 - near about N/N = 1) SC-O(h) */
    }
};

bool twoSum(Node *root, int tar)
{
    if (root == NULL)
        return false;

    // next
    BSTIterator l(root, false);
    // before
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next(); // r.before()

    while (i < j)
    {
        if (i + j == tar)
            return true;
        else if (i + j < tar)
            i = l.next();
        else
            j = r.next();
    }
    return false;

    /*  TC-O(n) SC-O(h + h = 2h) */
}