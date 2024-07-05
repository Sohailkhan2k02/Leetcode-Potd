//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>vc;
        int maxi=INT_MIN, mini=INT_MAX;
        ListNode*temp = head;
        ListNode*prev = NULL;
        ListNode*nxt = temp->next;
        int cnt = 1;

        while(nxt!=NULL && nxt->next!=NULL) {
            prev=temp;
            temp=nxt;
            nxt=nxt->next;
            cnt++;
            if ((temp->val>prev->val && temp->val>nxt->val) || (temp->val<prev->val && temp->val<nxt->val)) {
                vc.push_back(cnt);
            }
        }

        if(vc.size()<=1) return {-1,-1};
        // for(auto i: vc){
        //     cout<<i<<" ";
        // }
        maxi=vc.back()-vc.front();
        for (int i=1; i<vc.size(); i++) {
            mini=min(mini,vc[i]-vc[i-1]);
        }
        return {mini, maxi};
    }
};
