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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        while (n--)fast=fast->next;
        while (fast!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(prev==NULL)head=head->next;
        else prev->next=slow->next;
        return head; 
    }
};