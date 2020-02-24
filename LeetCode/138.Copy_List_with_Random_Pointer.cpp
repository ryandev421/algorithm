/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    map<Node*, Node*> cloned_node_map;
    
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        
        Node *res, *newNode;
        Node *cur = head;
        while (cur != NULL) {
            newNode = getClonedNode(cur);
            if (cur == head) {
                res = newNode;
            }
            newNode->next = getClonedNode(cur->next);
            newNode->random = getClonedNode(cur->random);
            cur = cur->next;
        }
        
        return res;
    }
    
    Node* getClonedNode(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        if (cloned_node_map.find(node) == cloned_node_map.end()) {
            cloned_node_map[node] = new Node(node->val);
        }
        
        return cloned_node_map[node];
    }
};