//Approach-1
//T.C : O(str.length())
//S.C : O(26) ~ O(1)
class Solution {
public:
    string customSortString(string order, string str) {
        int count[26] = {0};
        
        for(char &x : str)
            count[x-'a']++;
        
        string result = "";
        for(char &ch : order) {
            while(count[ch-'a']--) {
                result.push_back(ch);
            }
        }
        for(char &ch : str) {
            if(count[ch-'a'] > 0) {
                result.push_back(ch);
            }
        }
        
        return result;
    }
};

//Approach-2 (Using comparator)
//T.C : O(nlogn)
//S.C : O(26) ~ O(1)
class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> index(26, -1);
        
        for(int i = 0; i<order.length(); i++)
            index[order[i]-'a'] = i;
        
        
        auto lambda = [&index](char &ch1, char &ch2) {
            return index[ch1-'a'] < index[ch2-'a'];
        };
        
        sort(begin(str), end(str), lambda);
        return str;
        
    }
};
//Approach -3
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mpp;
        for(auto i:s){
            mpp[i]++;
        }
        string res="";
        for(auto i:order){
            if(mpp.find(i)!=mpp.end()){
                res.append(mpp[i],i);
                mpp.erase(i);
            }
        }

        for(auto i:mpp){
            res.append(i.second,i.first);
        }
        return res;
    }
};
