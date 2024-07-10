// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* tmp = dummy;
        while (tmp->next and tmp->next->next) {
            if (tmp->next->val == tmp->next->next->val) {
                int dup = tmp->next->val;
                while (tmp and tmp->next and tmp->next->val == dup) {
                    tmp->next = tmp->next->next;
                }
            } else
                tmp = tmp->next;
        }
        return dummy->next;
    }
};