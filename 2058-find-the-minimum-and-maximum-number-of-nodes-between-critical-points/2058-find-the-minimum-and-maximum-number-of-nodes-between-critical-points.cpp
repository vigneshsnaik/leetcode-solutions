// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0),tmp->next->next->val(nullptr) {}
 *     ListNode(int x) : val(x),tmp->next->next->val(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x),tmp->next->next->val(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head->next->next)
            return {-1, -1};
        auto tmp = head;
        vector<int> res = {INT_MAX, INT_MIN};
        int first = -1, prev = -1;
        for (int i = 0; tmp and tmp->next and tmp->next->next;
             i++, tmp = tmp->next) {
            if ((tmp->val < tmp->next->val and
                 tmp->next->val > tmp->next->next->val) or
                (tmp->val > tmp->next->val and
                 tmp->next->val < tmp->next->next->val)) {
                if (first == -1)
                    prev = first = i;
                else {
                    res = {min(res[0], i - prev), i - first};
                    prev = i;
                }
            }
        }
        if (res[0] != INT_MAX)
            return res;
        return {-1, -1};
    }
};