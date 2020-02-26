/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        ListNode *cur = NULL;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                if (cur != NULL) {
                    cur->next = l1;
                }
                cur = l1;
                l1 = l1->next;
            } else {
                if (cur != NULL) {
                    cur->next = l2;
                }
                cur = l2;
                l2 = l2->next;
            }
            if (res == NULL) {
                res = cur;
            }
        }
        
        while (l1 != NULL) {
            if (cur != NULL) {
                cur->next = l1;
            }
            cur = l1;
            if (res == NULL) {
                res = cur;
            }
            l1 = l1->next;
        }
        
        while (l2 != NULL) {
            if (cur != NULL) {
                cur->next = l2;
            }
            cur = l2;
            if (res == NULL) {
                res = cur;
            }
            l2 = l2->next;
        }
        
        return res;
    }
};