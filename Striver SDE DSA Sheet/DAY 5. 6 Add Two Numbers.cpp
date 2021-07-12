
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int num1 = 0;
        int num2 = 0;
        int pow1 = 1;
        int pow2 = 1;
        while (l1 != NULL)
        {
            int x = l1->val;
            num1 = num1 + (x * pow1);
            l1 = l1->next;
            pow1 = pow1 * 10;
        }
        while (l2 != NULL)
        {
            int x = l2->val;
            num2 = num2 + (x * pow2);
            l2 = l2->next;
            pow2 = pow2 * 10;
        }
        int res = int(num1 + num2);

        vector<int> digits;
        if (res == 0)
        {
            digits.push_back(0);
        }
        while (res > 0)
        {
            int rem = res % 10;
            digits.push_back(rem);
            res = res / 10;
        }
        ListNode ans(0);
        ListNode *tail = &ans;
        int i = 0;
        while (i < digits.size())
        {
            tail->next = new ListNode(digits[i]);
            tail = tail->next;
            i++;
        }
        return ans.next;
    }
};