#include <set>
using namespace std;

struct Segment {
   int index;
   long long value;
   long long mergeCost;
   Segment* left = nullptr;
   Segment* right = nullptr;
};

struct Compare {
   bool operator()(Segment* a, Segment* b) const {
       if (!a->right || !b->right) return a->right != nullptr;
       if (a->mergeCost != b->mergeCost)
           return a->mergeCost < b->mergeCost;
       return a->index < b->index;
   }
};

class Solution {
public:
   int minimumPairRemoval(vector<int>& nums) {
       set<Segment*, Compare> heap;
       int violations = 0;

       Segment* prev = nullptr;
       vector<Segment*> nodes;

       for (int i = 0; i < nums.size(); i++) {
           Segment* cur = new Segment{i, nums[i], 0};
           nodes.push_back(cur);

           if (prev) {
               if (cur->value < prev->value) violations++;
               prev->right = cur;
               cur->left = prev;
               prev->mergeCost = prev->value + cur->value;
               heap.insert(prev);
           }
           prev = cur;
       }
       heap.insert(prev);

       int ops = 0;

       while (violations > 0) {
           ops++;
           auto it = heap.begin();
           Segment* best = *it;
           heap.erase(it);

           Segment* nxt = best->right;
           if (nxt->value < best->value) violations--;

           best->value += nxt->value;
           best->right = nxt->right;

           if (nxt->right) {
               if (nxt->right->value < nxt->value) violations--;
               nxt->right->left = best;
               if (best->value > nxt->right->value) violations++;
           }

           heap.insert(best);

           if (best->left) {
               Segment* p = best->left;
               heap.erase(p);

               if (p->value > best->value) violations++;
               p->mergeCost = p->value + best->value;
               heap.insert(p);
           }
       }
       return ops;
   }
};
