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
void append(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}
int revv(int num)
{

    int answer = 0;
    int multiplier = countDigit(num) - 1;
    while (num > 0)
    {
        int x = num % 10;
        answer += (pow(10, multiplier) * x);
        multiplier--;
        num = num / 10;
    }
    return answer;
}

struct Node *contruct(int num)
{
    struct Node *head = NULL;

    while (num > 0)
    {
        int data = num % 10;
        append(&head, data);
        num = num / 10;
    }
    return head;
}

int main()
{
    struct Node *first = newNode(7);
    first->next = newNode(1);
    first->next->next = newNode(6);

    struct Node *second = newNode(5);
    second->next = newNode(9);
    second->next->next = newNode(2);

    int first_num = findnum(first);
    int second_num = findnum(second);
    int result_num = first_num + second_num;
    result_num = revv(result_num);
    //cout << result_num << endl;
    struct Node *head = contruct(result_num);
    printList(head);
    //struct Node *result = construct(result_num);
}