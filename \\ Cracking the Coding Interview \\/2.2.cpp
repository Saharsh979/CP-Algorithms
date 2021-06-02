#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *
newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int length(struct Node *node)
{
    int length = 0;
    while (node != NULL)
    {
        length++;
        node = node->next;
    }
    return length;
}

void removekth(struct Node *start, int index)
{
    struct Node *curr = start;
    struct Node *prev = NULL;
    int idx = 0;
    for (idx = 0; idx <= index; idx++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
}

int main()
{
    struct Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(12);
    start->next->next->next->next = newNode(10);
    start->next->next->next->next->next = newNode(12);
    start->next->next->next->next->next->next = newNode(12);

    int size = length(start);
    cout << size << endl;
    int k;
    cin >> k;

    removekth(start, size - k - 1);
    cout << endl;

    printList(start);
}