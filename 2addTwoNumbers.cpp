/**
 * source: https://leetcode-cn.com/problems/add-two-numbers/
 * author: WEN JINGJING
 * date: 2020.7.01
 */

/**
 * Question description: 
 * Two non empty linked lists are given to represent two nonnegative integers. 
 * Their respective bits are stored in reverse order, and each node can only store one digit.
 * If we add these two numbers together, we will return a new linked list to represent their sum.
 * You can assume that neither of these numbers begins with a 0, except for the number 0.
 * 
 * Example:
 * input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * output: 7 -> 0 -> 8
 * as: 342 + 465 = 807
 */

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *Head = new ListNode(0);//创建头结点
        ListNode *temp = Head;//移动结点
        int carry = 0;
        while (l1 != NULL || l2 != NULL)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            temp = temp->next;
        }
        if (carry)
        {
            temp->next = new ListNode(1);
        }
        return Head->next;
    }
};