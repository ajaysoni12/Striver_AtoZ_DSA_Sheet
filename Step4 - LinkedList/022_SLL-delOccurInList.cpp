#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

/* method 1 (brute force approach: using extra space) */
Node *deleteKey1(Node *head, int key)
{
    if (head == NULL)
        return head;

    Node *newHead = new Node(-1);
    Node *curr_ptr = newHead;

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data != key)
        {
            curr_ptr->next = new Node(curr->data);
            curr_ptr = curr_ptr->next;
        }
        curr = curr->next;
    }
    return newHead->next;
    /*  TC-O(n)
        SC-(n) */
}

/* method 2 (optimize approach: wihtout extra space) */
Node *deleteKey(Node *head, int key)
{
    if (head == NULL)
        return head;

    Node *newHead = new Node(-1);
    Node *curr_ptr = newHead;

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data != key)
        {
            curr_ptr->next = curr;
            curr_ptr = curr_ptr->next;
        }
        curr = curr->next;
    }
    return newHead->next;
    /*  TC-O(n)
        SC-(1) */
}

Node *push(Node *head, int new_data)
{
    Node *new_node = new Node(new_data);
    new_node->next = head;
    head = new_node;
    return head;
}

void printList(Node *node)
{
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

// Driver code
int main()
{

    // Start with the empty list
    Node *head = NULL;
    head = push(head, 7);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 8);
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 2);

    // Key to delete
    int key = 2;
    cout << "Created Linked List:\n ";
    printList(head);
    // Function call
    head = deleteKey(head, key);

    if (!head)
        cout << "\nNo element present in the Linked list"
             << endl;
    else
    {
        cout << "\nLinked List after Deletion is:\n";
        printList(head);
    }
    return 0;
}