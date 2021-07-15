/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a1 = headA;
        ListNode *a3 = NULL;
        ListNode *a2 = headB;
        if (headA == NULL || headB == NULL)
        {
            ListNode *res = NULL;
            return res;
        }
        if (a1 == a2)
        {
            return a1;
        }
        while (a1 != NULL && a2 != NULL && a1 != a2)
        {
            a1 = a1->next;
            a2 = a2->next;
            if (a1 == a2)
            {
                return a1;
            }

            if (a1 == NULL)
            {
                a1 = headB;
            }
            if (a2 == NULL)
            {
                a2 = headA;
            }
        }

        return a1;
    }
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *cur1 = headA, *cur2 = headB;
        while (cur1 != cur2)
        {
            cur1 = cur1 ? cur1->next : headB;
            cur2 = cur2 ? cur2->next : headA;
        }
        return cur1;
    }
};

//EZOZWC+BookAntiqua,Bold