// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* hare=head;
        ListNode* tortoise=head;
        while (hare&&hare->next){
            hare=hare->next->next;
            tortoise=tortoise->next;
        } 
        return tortoise;
    }
};