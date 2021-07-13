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
    bool hasCycle(ListNode *head)
    {
        ListNode *walker = head;
        ListNode *runner = head;
        if (head == NULL || head->next == NULL)
            return false;

        while (runner->next != NULL && runner->next->next != NULL)
        {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner)
            {
                return true;
            }
        }
        return false;
    }
};