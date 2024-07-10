// https://leetcode.com/problems/merge-k-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* list = dummy;
        while (list1 and list2) {
            if (list1->val <= list2->val) {
                list->next = list1;
                list1 = list1->next;
            } else {
                list->next = list2;
                list2 = list2->next;
            }
            list = list->next;
        }
        if (list1)
            list->next = list1;
        else
            list->next = list2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        for (int i = 1; i < lists.size(); i++) {
            lists[i] = mergeTwoLists(lists[i], lists[i - 1]);
        }
        return lists.back();
    }
};