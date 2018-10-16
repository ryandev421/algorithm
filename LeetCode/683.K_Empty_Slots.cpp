struct NODE
{
    int pos;
    int val;
    bool operator()(NODE p, NODE q)
    {
        return p.val > q.val;
    }
};

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int slot_count = flowers.size();
        if (k > slot_count-2) return -1;
        
        vector<int> slots(slot_count + 1);
        vector<NODE> heap;
        int res = std::numeric_limits<int>::max();
        for (int  i = 0; i < slot_count; i++) {
            slots[flowers[i]] = i+1;
        }
        for (int i = 2; i <= k+1;i++) {
            NODE tmp;
            tmp.pos = i;
            tmp.val = slots[i];
            heap.push_back(tmp);
        }
        make_heap(heap.begin(), heap.end(), NODE());
        for (int le = 1, ri = k+2; ri <= slot_count; le++, ri++) {
            int min_val = (heap.size() !=0) ? heap[0].val : std::numeric_limits<int>::max();
            if (min_val > max(slots[le], slots[ri])) {
                res = min(res, max(slots[le], slots[ri]));
            }
            while(heap.size() != 0) {
                NODE min_node = heap[0];
                if (min_node.pos <= le+1) {
                    pop_heap(heap.begin(), heap.end(), NODE());
                    heap.pop_back();
                } else {
                    break;
                }
            }
            if (k!=0) {
                NODE ri_node;
                ri_node.pos = ri;
                ri_node.val = slots[ri];
                heap.push_back(ri_node);
                push_heap(heap.begin(), heap.end(), NODE());
            }
        }
        
        return (res != std::numeric_limits<int>::max()) ? res : -1;
    }
};