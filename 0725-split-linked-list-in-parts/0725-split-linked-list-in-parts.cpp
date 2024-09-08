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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, NULL);
        ListNode* tmp = head;
        int len = 0;
        while (tmp) {
            tmp = tmp->next;
            len++;
        }
        int size = len / k, extra = len % k;
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* partHead = curr;
            int partSize = size + (extra > 0 ? 1 : 0);
            extra--;
            for (int j = 1; j < partSize; j++) {
                if (curr) {
                    curr = curr->next;
                }
            }
            if (curr) {
                ListNode* nextPartHead = curr->next;
                curr->next = NULL;
                curr = nextPartHead;
            }
            res[i] = partHead;
        }
        return res;
    }
};