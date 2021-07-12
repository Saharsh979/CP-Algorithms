/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return nullptr;

        ListNode new_head(-1);
        new_head.next = head;

        ListNode *slow = &new_head, *fast = &new_head;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *to_de_deleted = slow->next;
        slow->next = slow->next->next;

        return new_head.next;
    }
};