class Solution {
public:
    string smallestSubsequence(string s) {
         unordered_map<char,int>freq;
        set<char>st;
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]]++;
            st.insert(s[i]);
        }
        unordered_map<char,bool>visited;
        for(auto &it:st)
        {
            visited[it]=false;
        }
        stack<char>stk;
        for(int i=0;i<s.length();i++)
        {
            char ele=s[i];
            if(stk.empty())
            {
                stk.push(ele);
                freq[ele]--;
                visited[ele]=true;
                continue;
            }
            while(!stk.empty() && stk.top()>=ele && freq[stk.top()]!=0 && !visited[ele])
            {
                visited[stk.top()]=false;
                stk.pop();
            }
            if(!visited[ele]) 
            {
                stk.push(ele);
                freq[ele]--;
                visited[ele]=true;
            }
            else freq[ele]--;
        }
        string ans="";
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
