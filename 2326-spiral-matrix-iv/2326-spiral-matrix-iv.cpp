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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int t = 0, b = m - 1, l = 0, r = n - 1;
        while (t <= b && l <= r && head) {
            for (int j = l; j <= r && head; ++j) {
                matrix[t][j] = head->val;
                head = head->next;
            }
            t++;
            for (int i = t; i <= b && head; ++i) {
                matrix[i][r] = head->val;
                head = head->next;
            }
            r--;
            if (t <= b)
                for (int j = r; j >= l && head; --j) {
                    matrix[b][j] = head->val;
                    head = head->next;
                }
            b--;
            if (l <= r)
                for (int i = b; i >= t && head; --i) {
                    matrix[i][l] = head->val;
                    head = head->next;
                }
            l++;
        }
        return matrix;
    }
};
