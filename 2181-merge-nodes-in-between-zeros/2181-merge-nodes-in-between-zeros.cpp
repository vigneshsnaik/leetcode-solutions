// https://leetcode.com/problems/merge-nodes-in-between-zeros

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* tmp = head;
        while (tmp and tmp->next) {
            while (tmp->next and tmp->next->next and tmp->next->next->val) {
                tmp->next->val += tmp->next->next->val;
                tmp->next->next = tmp->next->next->next;
            }
            tmp->next->next = tmp->next->next->next;
            tmp = tmp->next;
        }
        return head->next;
    }
};