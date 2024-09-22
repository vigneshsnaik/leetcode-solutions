/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* copyOf[101];
    Node* dfs(Node* curr) {
        if (copyOf[curr->val]) {
            return copyOf[curr->val];
        }
        auto newNode = new Node(curr->val);
        copyOf[curr->val] = newNode;
        for (auto neighbor : curr->neighbors) {
            newNode->neighbors.push_back(dfs(neighbor));
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        return dfs(node);
    }
};