// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next)return head;
        ListNode* odd=head;
        ListNode* evnHead=head->next;
        ListNode* evn=evnHead;
        while (evn != nullptr && evn->next != nullptr) {
            odd->next=evn->next;
            odd=odd->next;
            evn->next=odd->next;
            evn=evn->next;
        }
        odd->next=evnHead;
        return head;
    }
};