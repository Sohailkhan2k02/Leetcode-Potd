//T.C : O(n)
//S.C : O(1)
struct Node{
    Node* links[26];
    bool flag;
    int vis = 0;
    bool contains(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch){
        links[ch-'a']=new Node();
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root= new Node();
    }
    void insert(string s){
        Node* node=root;
        for(auto&i:s){
            if(!node->contains(i)){
                node->put(i);
            }
            node=node->get(i);
            node->vis++;
        }
        node->flag=true;
    }
    int sumWith(string s){
        Node* node=root;
        int sum=0;
        for(auto&i:s){
            node=node->get(i);
            sum+=node->vis;
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(auto&i:words){
            trie.insert(i);
        }
        vector<int> ans;
        for(auto&i:words){
            ans.push_back(trie.sumWith(i));
        }
        return ans;
    }
};
