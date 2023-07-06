#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

void PrintList(ListNode *head) // Function to print the LinkedList
{
    ListNode *curr = head;
    for (; curr != NULL; curr = curr->next)
        cout << curr->val << "-->";
    cout << "null" << endl;
}

ListNode *InsertatFirst(int value, ListNode *head)
{

    // Step1 : creating a new Node with the given val
    ListNode *newnode = new ListNode(value);

    // Step2 : Making next of newly created Node to point the head of LinkedList
    newnode->next = head;

    // Making the newly created Node as head
    head = newnode;
    return head;
}

void InsertatLast(int value, ListNode *head, ListNode *tail)
{
    // Step1 : creating a new Node with the given val
    ListNode *newnode = new ListNode(value);

    // If head is null, there are no nodes in LinkedList.
    // So the head and tail will be the newly created Node itself.
    if (head == nullptr)
        head = newnode, tail = newnode;

    else
    {
        // Step2 : Making tail's next point to newly created Node
        tail->next = newnode;

        // Making newly inserted Node as tail
        tail = newnode;
    }
}

int main()
{
    ListNode *head = NULL; // head of the LinkedList
    head = InsertatFirst(40, head);
    head = InsertatFirst(30, head);
    head = InsertatFirst(20, head);
    head = InsertatFirst(10, head);
    cout << "LinkedList before inserting 0 at beginning : " << endl;
    PrintList(head);
    head = InsertatFirst(0, head);
    cout << "LinkedList after inserting 0 at beginning : " << endl;
    PrintList(head);
    return 0;
}