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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num);
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* tmp = dummy;
        while (tmp->next) {
            if (s.find(tmp->next->val) != s.end()) {
                tmp->next = tmp->next->next;
            } else {
                tmp = tmp->next;
            }
        }
        return dummy->next;
    }
};