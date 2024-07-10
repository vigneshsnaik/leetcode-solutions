// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next)return NULL;
        ListNode* hare=head;
        ListNode* tort=head;
        while(hare&&hare->next){
            hare=hare->next->next;
            tort=tort->next;
        }
        if(!tort->next){
            head->next=NULL;
            return head;
        }
        tort->val=tort->next->val;
        tort->next=tort->next->next;
        return head;
    }
};