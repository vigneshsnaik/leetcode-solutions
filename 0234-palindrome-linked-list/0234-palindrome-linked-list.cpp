// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; 
        ListNode* fast = head;
        ListNode* slow = head;
        stack<int> s;
        while (fast && fast->next) {
            s.push(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) {
            slow = slow->next; 
        } 
        while (slow) {
            if (!s.empty() && slow->val == s.top()) {
                s.pop();
                slow = slow->next;
            } else {
                return false;
            }
        }
        
        return true;
    }
};