/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal, NULL);
            head->next = head;
        } else {
            Node *cur_node = head;
            Node *next_node = head->next;
            while(next_node != head) {
                if ((cur_node->val <= insertVal && insertVal <= next_node->val)
                    || (cur_node->val > next_node->val && next_node->val >= insertVal)
                    || (cur_node->val > next_node->val && cur_node->val <= insertVal)) {
                    break;
                }
                cur_node = next_node;
                next_node = next_node->next;
            }
            Node * new_node = new Node(insertVal, next_node);
            cur_node->next = new_node;
        }
        return head;
    }
};
