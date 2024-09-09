//T.C : O(n*m) + O(linkedlist length)
//S.C : O(n*m)
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>>res(n,vector<int>(m,-1));
        int left=0,top=0,right=m-1,bottom=n-1;
        while(left<=right && top<=bottom){
            for(int i=left; i<=right; i++){
                if(head!=NULL){
                    res[top][i]=head->val;
                    head=head->next;
                }
            }
            top++;

            for(int i=top; i<=bottom; i++){
                if(head!=NULL){
                    res[i][right]=head->val;
                    head=head->next;
                }
            }
            right--;

            if(top<=bottom){
                for(int i=right; i>=left; i--){
                    if(head!=NULL){
                        res[bottom][i]=head->val;
                        head=head->next;
                    }
                }
                bottom--;
            }

            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    if(head!=NULL){
                        res[i][left]=head->val;
                        head=head->next;
                    }
                }
                left++;
            }
        }
        return res;
    }
};
