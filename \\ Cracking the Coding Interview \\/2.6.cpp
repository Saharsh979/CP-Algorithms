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
int findnum(struct Node *node)
{
    int val = 0;
    int multiplier = 0;
    while (node != NULL)
    {
        val = val + (pow(10, multiplier) * (node->data));
        multiplier++;
        node = node->next;
    }
    return val;
}
int countDigit(int n)
{
    return floor(log10(n) + 1);
}

int main()
{
    struct Node *first = newNode(7);
    first->next = newNode(1);
    first->next->next = newNode(6);
    first->next->next->next = newNode(7);
    first->next->next->next->next = newNode(7);

    int number = findnum(first);
    string x = to_string(number);
    string revx = x;
    reverse(revx.begin(), revx.end());
    bool flag = true;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == revx[i])
        {
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    //string revx = reverse(x);
    //cout << x << " " << revx << endl;
}