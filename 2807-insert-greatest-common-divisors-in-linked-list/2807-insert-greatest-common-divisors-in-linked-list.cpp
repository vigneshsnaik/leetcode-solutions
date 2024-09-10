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
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* tmp = head;
        while (tmp->next) {
            tmp->next = new ListNode(gcd(tmp->val, tmp->next->val), tmp->next);
            tmp = tmp->next->next;
        }
        return head;
    }
};