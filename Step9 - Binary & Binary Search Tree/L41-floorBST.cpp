#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int floorBST(Node *root, int key)
{
    int floor = -1;
    while (root)
    {
        if (root->data == key)
        {
            floor = root->data;
            return floor;
        }
        else if (key > root->data)
        {
            floor = root->data;
            root = root->right;
        }
        else
            root = root->left;
    }
    return floor;
    /*  TC-O(log2(n)) SC-O(1) */
}