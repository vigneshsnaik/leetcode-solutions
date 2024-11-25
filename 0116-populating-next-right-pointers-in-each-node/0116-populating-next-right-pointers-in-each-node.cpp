/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* right = NULL;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto tmp = q.front();
                q.pop();
                tmp->next = right;
                right = tmp;
                if (tmp->right) {
                    q.push(tmp->right);
                    q.push(tmp->left);
                }
            }
        }
        return root;
    }
};
