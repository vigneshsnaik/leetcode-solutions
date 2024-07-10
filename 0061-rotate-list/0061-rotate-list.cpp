// https://leetcode.com/problems/rotate-list


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!k || !head || !head->next)
            return head;
        ListNode* tmp = head;
        int n = 1;
        while (tmp->next) {
            tmp = tmp->next;
            n++;
        }
        k = n - k % n;
        tmp->next = head;
        while (k--) {
            tmp = tmp->next;
        }
        head = tmp->next;
        tmp->next= NULL;
        return head;
    }
};