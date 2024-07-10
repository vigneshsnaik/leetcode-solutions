// https://leetcode.com/problems/linked-list-cycle-ii

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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
        {
            return NULL;
        }
        
        ListNode *slow=head;
        ListNode *fast=head->next;
        if (!fast||!slow||!fast->next||!slow->next)
        {
            return NULL;
        }    
        while (slow&&fast->next&&slow->next&&fast->next->next)
        {
            if (slow==fast)
            {
                fast=fast->next;
                slow=head;
                while(fast!=slow){
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return NULL;
    }
};