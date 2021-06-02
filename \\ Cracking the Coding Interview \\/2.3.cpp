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

void remove(struct Node *start, int index)
{
    struct Node *curr = start;
    struct Node *prev = NULL;
    int idx = 0;
    for (idx = 0; idx < index - 1; idx++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
}

int main()
{
    struct Node *start = newNode(1);
    start->next = newNode(2);
    start->next->next = newNode(3);
    start->next->next->next = newNode(4);
    start->next->next->next->next = newNode(5);
    start->next->next->next->next->next = newNode(6);
    start->next->next->next->next->next->next = newNode(7);
    int middle;
    printList(start);
    cout << endl;
    int len = length(start);
    if (len <= 2)
    {
        cout << "NOT Possible" << endl;
    }
    else
    {
        if (len % 2 == 1)
        {
            middle = (len + 1) / 2;
        }
        else
        {
            middle = len / 2;
        }
        cout << middle << endl;
        remove(start, middle);
    }

    printList(start);
}