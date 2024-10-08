// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)return NULL;
        ListNode* dummy=new ListNode(0,head);
        ListNode* tmp=dummy;
        while(tmp!=NULL)
            if(tmp->next!=NULL&&tmp->next->val==val)tmp->next=tmp->next->next;
            else tmp=tmp->next;
        return dummy->next;
    }
};