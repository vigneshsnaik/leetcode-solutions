// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list

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
    int doubler(ListNode* head){
        if(!head)return 0;
        int tmp=2*head->val+doubler(head->next);
        head->val=tmp%10;
        return tmp/10;
    }
    ListNode* doubleIt(ListNode* head) {
        return doubler(head)?new ListNode(1,head):head;    
    }
};