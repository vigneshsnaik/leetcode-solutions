// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head, Node* child = NULL) {
        if (!head)
            return child;
        head->next = flatten(head->child, flatten(head->next, child));
        if (head->next)
            head->next->prev = head;
        head->child = NULL;
        return head;
    }
};