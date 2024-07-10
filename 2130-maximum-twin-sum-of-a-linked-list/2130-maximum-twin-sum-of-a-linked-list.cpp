// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=head;
        while(curr!=NULL){
            next=next->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* middleList(ListNode* head) {
        if(!head->next)return NULL;
        ListNode* hare=head;
        ListNode* tort=head;
        while(hare->next&&hare->next->next){
            hare=hare->next->next;
            tort=tort->next;
        }
        return tort;
    }
    int pairSum(ListNode* head1) {
        if(!head1->next->next)return head1->val+head1->next->val;
        ListNode* head2=reverseList(middleList(head1));
        int res=INT_MIN;
        while(head1){
            res=max(res,head1->val+head2->val);
            head1=head1->next;
            head2=head2->next;
        }
        return res;
    }
};