// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
        {
            return false;
        }
        ListNode *slow=head;
        ListNode *fast=head->next;
        if (!fast||!slow||!fast->next||!slow->next)
        {
            return false;
        }    
        while (slow&&fast->next&&slow->next&&fast->next->next)
        {
            if (slow==fast)
            {
                return true;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }
};