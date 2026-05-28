struct node{
    int idx;
    map<int, node*>ch;
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& dict, vector<string>& queries) {
        int n = dict.size();
        node* root = new node();
        int mnl=1e8, id=-1;
        for(int j=0; j<n; j++){
            node* itr= root;
            string s = dict[j];
            int l=s.length();
            if(l < mnl){
                mnl = l;
                id = j;
            }
            for(int i=l-1; i>=0; --i){
                if(itr -> ch[s[i]-'a']){
                    itr = itr->ch[s[i]-'a'];
                    if(l < dict[itr -> idx].length()){
                        itr -> idx = j;
                    }
                }
                else{
                    itr -> ch[s[i]-'a'] = new node();
                    itr = itr->ch[s[i]-'a'];
                    itr -> idx = j;
                }
            }
        }
        root->idx = id;
        vector<int> ans;
        for(auto q : queries){
            int l=q.length();
            node* itr = root;
            for(int i=l-1; i>=0; --i){
                if(itr -> ch[q[i] - 'a']){
                    itr = itr -> ch[q[i] - 'a'];
                }
                else break;
            }
            ans.push_back(itr->idx);
        }
        return ans;
    }
};
