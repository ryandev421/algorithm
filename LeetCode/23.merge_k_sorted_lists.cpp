/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool Compare(const ListNode* p, const ListNode* q)
{
    return p->val > q->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> heap;
        for (int i = 0 ; i < lists.size(); ++i) {
            heap.push_back(lists[i]);
        }
        make_heap(heap.begin(), heap.end(), Compare);
        
        ListNode *res = NULL;
        ListNode *now = NULL;
        
        while (heap.size() != 0) {
            ListNode *minNode = heap[0];
            pop_heap(heap.begin(), heap.end(), Compare);
            heap.pop_back();
            
            if (res == NULL) {
                res = minNode;
                now = minNode;
            } else {
                now->next = minNode;
                now = minNode;
            }
            if (now->next != NULL) {
                heap.push_back(now->next);
                push_heap(heap.begin(), heap.end(), Compare);
            }
            now->next = NULL;
        }
        
        return res;
    }
};


