
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        int carry = (l1->val + l2->val) / 10;
        ListNode *l3 = new ListNode((l1->val + l2->val) % 10);
        ListNode *tail = l3;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 || l2 || carry)
        {
            int sum = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry);
            ListNode *t = new ListNode(sum % 10);
            carry = sum / 10;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            tail->next = t;
            tail = t;
        }

        return l3;
    }
};